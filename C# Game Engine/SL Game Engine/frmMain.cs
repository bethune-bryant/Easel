using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Threading;
using System.Windows.Forms;
using System.IO;

namespace SL_Game_Engine
{
    public partial class frmMain : Form
    {
        #region Statics

        private static bool DEBUG_MODE = false;

        private const int FPS = 30;

        private static int currentFPS = FPS;

        public static string slFile = "";

        private static string keyPresses = "";
        private static Queue<MouseEventArgs> mouseClicks = new Queue<MouseEventArgs>();

        private static Point cursorPosition = new Point();

        private static Queue<string> sounds = new Queue<string>();

        private static int frameCount = 0;
        private static double totalFrameCount = 0;
        private static double drawnFrameCount = 0;
        private static DateTime totalStartTime = DateTime.UtcNow;

        private static Dictionary<string, Image> GameImages = new Dictionary<string, Image>();

        #endregion

        #region ThreadSafe Image Maintinence

        private static List<SLImage> bufferDraw = new List<SLImage>();
        private static List<SLImage> toDraw = new List<SLImage>();

        private static bool imageUpdated = false;

        private bool ImageUpdated
        {
            get
            {
                return imageUpdated;
            }
            set
            {
                if (!imageUpdated && value)
                {
                    toDraw = new List<SLImage>(bufferDraw);
                }
                imageUpdated = value;
            }
        }

        private void DrawState()
        {
            bufferDraw = SLInterface.getImages();
            ImageUpdated = true;
        }

        private void picDisplay_Paint(object sender, PaintEventArgs e)
        {
            //e.Graphics.CompositingMode = System.Drawing.Drawing2D.CompositingMode.SourceCopy; messes up transparency
            e.Graphics.CompositingQuality = System.Drawing.Drawing2D.CompositingQuality.HighSpeed;
            e.Graphics.PixelOffsetMode = System.Drawing.Drawing2D.PixelOffsetMode.None;
            e.Graphics.SmoothingMode = System.Drawing.Drawing2D.SmoothingMode.None;
            e.Graphics.InterpolationMode = System.Drawing.Drawing2D.InterpolationMode.Default;

            for (int i = 0; i < toDraw.Count; i++)
            {
                switch (toDraw[i].Kind)
                {
                    case (SLImage.Kinds.Segment):
                        e.Graphics.DrawLine(new Pen(toDraw[i].Color, 1), toDraw[i].End1, toDraw[i].End2);
                        break;
                    case (SLImage.Kinds.Circle):
                        e.Graphics.DrawEllipse(new Pen(toDraw[i].Color, 1), toDraw[i].Center.X - toDraw[i].Radius, toDraw[i].Center.Y - toDraw[i].Radius, toDraw[i].Radius * 2, toDraw[i].Radius * 2);
                        break;
                    case (SLImage.Kinds.Disc):
                        e.Graphics.FillEllipse(new Pen(toDraw[i].Color, 1).Brush, toDraw[i].Center.X - toDraw[i].Radius, toDraw[i].Center.Y - toDraw[i].Radius, toDraw[i].Radius * 2, toDraw[i].Radius * 2);
                        break;
                    case (SLImage.Kinds.Text):
                        Font font = new Font(FontFamily.GenericMonospace,toDraw[i].Height, FontStyle.Regular, GraphicsUnit.Pixel);
                        Size textSize = TextRenderer.MeasureText(toDraw[i].Message, font);
                        e.Graphics.DrawString(toDraw[i].Message, font, new Pen(toDraw[i].Color, 1).Brush, toDraw[i].Center.X - (textSize.Width / 2), toDraw[i].Center.Y - (textSize.Height / 2));
                        break;
                    case (SLImage.Kinds.Triangle):
                        List<Point> points = new List<Point>();
                        points.Add(toDraw[i].End1); points.Add(toDraw[i].End2); points.Add(toDraw[i].End3);
                        e.Graphics.FillPolygon(new Pen(toDraw[i].Color, 1).Brush, points.ToArray());
                        break;
                    case (SLImage.Kinds.Graphic):
                        if (!GameImages.ContainsKey(toDraw[i].FileLocation))
                        {
                            if (File.Exists(toDraw[i].FileLocation))
                            {
                                GameImages.Add(toDraw[i].FileLocation, Image.FromFile(toDraw[i].FileLocation, true));
                                if (ImageAnimator.CanAnimate(GameImages[toDraw[i].FileLocation]))
                                    ImageAnimator.Animate(GameImages[toDraw[i].FileLocation], null);
                            }
                            else
                            {
                                bgwEngine.CancelAsync();
                                MessageBox.Show("Image file " + toDraw[i].FileLocation + " doesn't exist.", "Can't find Image!", MessageBoxButtons.OK, MessageBoxIcon.Error);
                                break;
                            }
                        }
                        if (GameImages.ContainsKey(toDraw[i].FileLocation))
                        {
                            int graphicWidth = toDraw[i].Width > 0 ? toDraw[i].Width : GameImages[toDraw[i].FileLocation].Width;
                            int graphicHeight = toDraw[i].Height > 0 ? toDraw[i].Height : GameImages[toDraw[i].FileLocation].Height;

                            int destTopLeftX = toDraw[i].Center.X - (graphicWidth / 2);
                            int destTopLeftY = toDraw[i].Center.Y - (graphicHeight / 2);

                            if (destTopLeftX >= 0 && destTopLeftX + graphicWidth <= 1000 && destTopLeftY >= 0 && destTopLeftY + graphicHeight <= 800)
                            {
                                e.Graphics.DrawImage(GameImages[toDraw[i].FileLocation], destTopLeftX, destTopLeftY, graphicWidth, graphicHeight);
                            }
                            else if (!(destTopLeftX > 1000 || destTopLeftY > 800 || destTopLeftX + graphicWidth < 0 || destTopLeftY + graphicHeight < 0))
                            {
                                double destToSrc = (double)GameImages[toDraw[i].FileLocation].Width / graphicWidth;

                                graphicWidth += destTopLeftX < 0 ? destTopLeftX : 0;
                                graphicHeight += destTopLeftY < 0 ? destTopLeftY : 0;

                                graphicWidth = Math.Min(graphicWidth, 1000);
                                graphicHeight = Math.Min(graphicHeight, 800);

                                int srcTopLeftX = destTopLeftX < 0 ? -(int)(destTopLeftX * destToSrc) : 0;
                                int srcTopLeftY = destTopLeftY < 0 ? -(int)(destTopLeftY * destToSrc) : 0;

                                destTopLeftX = destTopLeftX < 0 ? 0 : destTopLeftX;
                                destTopLeftY = destTopLeftY < 0 ? 0 : destTopLeftY;

                                int srcWidth = (int)Math.Min(GameImages[toDraw[i].FileLocation].Width - srcTopLeftX, destToSrc * 1000);
                                int srcHeight = (int)Math.Min(GameImages[toDraw[i].FileLocation].Height - srcTopLeftY, destToSrc * 800);

                                e.Graphics.DrawImage(GameImages[toDraw[i].FileLocation], 
                                                     new Rectangle(destTopLeftX, destTopLeftY, graphicWidth, graphicHeight), 
                                                     new Rectangle(srcTopLeftX, srcTopLeftY, srcWidth, srcHeight), 
                                                     GraphicsUnit.Pixel);
                            }

                            if (ImageAnimator.CanAnimate(GameImages[toDraw[i].FileLocation])) ImageAnimator.UpdateFrames(GameImages[toDraw[i].FileLocation]);
                        }
                        break;
                }
            }
            drawnFrameCount++;
            ImageUpdated = false;
        }

        #endregion

        #region Initialization

        public frmMain(string[] args)
        {
            InitializeComponent();
            if (args.Length == 1)
            {
                slFile = args[0];
            }
        }

        private void frmMain_Shown(object sender, EventArgs e)
        {
            if (Execution.HasSequenceL && Execution.HasVS10)
            {
                if (slFile.Length == 0)
                {
                    if (openFileDialog.ShowDialog() == System.Windows.Forms.DialogResult.OK)
                    {
                        slFile = openFileDialog.FileName;
                    }
                }

                lblFrameRate.Text = "Compiling " + slFile;
                this.Text += " | " + lblFrameRate.Text;
            }

            bgwCompile.RunWorkerAsync();
        }

        private void frmMain_Load(object sender, EventArgs e)
        {
            if (!DEBUG_MODE)
            {
                statusStrip.Visible = false;

                this.MaximumSize = new Size(1016, 840);
                this.MinimumSize = new Size(1016, 840);
                this.Size = new Size(1016, 840);
            }
            else
            {
                this.MaximumSize = new Size(1016, 860);
                this.MinimumSize = new Size(1016, 860);
                this.Size = new Size(1016, 860);
            }
        }

        private void bgwCompile_DoWork(object sender, DoWorkEventArgs e)
        {
            if (slFile.Length > 0 && slFile != "nocompile")
            {
                Execution.Compile(slFile);
            }
        }

        private void bgwCompile_RunWorkerCompleted(object sender, RunWorkerCompletedEventArgs e)
        {
            if (slFile.Length > 0 && slFile != "nocompile")
            {
                System.Diagnostics.Process.Start(Application.ExecutablePath, "nocompile"); // to start new instance of application
                this.Close();
            }
            else if (EaselDLL.HasDll)
            {
                bgwEngine.RunWorkerAsync();
                timerFrameRate.Enabled = true;
                if (!DEBUG_MODE)
                {
                    statusStrip.Visible = false;
                    this.Text = "Easel SequenceL Game";
                }
            }
            else
            {
                MessageBox.Show("An EaselGame.dll does not exist!", "Error!", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        #endregion

        #region GameLoop

        private void bgwEngine_DoWork(object sender, DoWorkEventArgs e)
        {
            try
            {
                SLInterface.getInitialState();
                DrawState();

                totalStartTime = DateTime.UtcNow;

                while (!(sender as BackgroundWorker).CancellationPending)
                {
                    frameCount++;
                    totalFrameCount++;

                    DateTime start = DateTime.UtcNow;
                    bool clicked = false;
                    int x = 0;
                    int y = 0;

                    if (mouseClicks.Count > 0)
                    {
                        clicked = true;
                        x = mouseClicks.Peek().X;
                        y = (800 - mouseClicks.Peek().Y);
                        mouseClicks.Dequeue();
                    }
                    else
                    {
                        x = cursorPosition.X;
                        y = 800 - cursorPosition.Y;
                    }

                    foreach (string sound in SLInterface.getSounds(clicked, x, y, keyPresses))
                    {
                        sounds.Enqueue(sound);
                    }

                    SLInterface.getNewState(clicked, x, y, keyPresses);
                    if (!ImageUpdated)
                    {
                        DrawState();
                    }

                    (sender as BackgroundWorker).ReportProgress(0);


                    while (currentFPS > 0 && (DateTime.UtcNow - start).TotalMilliseconds < (1000.0 / currentFPS))
                    {
                        Thread.SpinWait(1);
                    }
                }
                e.Cancel = true;
                return;
            }
            catch (Exception exc)
            {
                MessageBox.Show(exc.Message, "Error!", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void bgwEngine_ProgressChanged(object sender, ProgressChangedEventArgs e)
        {
            if (ImageUpdated)
            {
                picDisplay.Invalidate(false);
            } 
            
            if (sounds.Count > 0)
            {
                SoundEngine.PlaySound(sounds.Dequeue());
            }

            try
            {
                cursorPosition = picDisplay.PointToClient(System.Windows.Forms.Cursor.Position);
            }
            catch
            {

            }
        }

        private void bgwEngine_RunWorkerCompleted(object sender, RunWorkerCompletedEventArgs e)
        {
            EaselDLL.slTerminate();
        }

        #endregion

        #region Key Listeners

        private void picDisplay_MouseDown(object sender, MouseEventArgs e)
        {
            mouseClicks.Enqueue(e);
        }

        private void frmMain_KeyDown(object sender, KeyEventArgs e)
        {
            string key = Convert.ToString(e.KeyData);

            if (key.Length == 1 && !keyPresses.Contains(key))
            {
                keyPresses += key;
            }

            e.Handled = true;
        }

        private void frmMain_KeyUp(object sender, KeyEventArgs e)
        {
            string key = Convert.ToString(e.KeyData);

            if (key.Length == 1 && keyPresses.Contains(key))
            {
                keyPresses = keyPresses.Replace(key, "");
            }

            e.Handled = true;
        }

        #endregion

        #region FrameRate

        static bool firstTick = true;

        private void timerFrameRate_Tick(object sender, EventArgs e)
        {
            int count = frameCount;
            frameCount = 0;

            if (DEBUG_MODE)
            {
                lblFrameRate.Text = "Target Frame Rate: " + currentFPS + "    Current Frame Rate: " + count + " FPS" + "     Average Frame Rate: " + Math.Round(totalFrameCount / (DateTime.UtcNow - totalStartTime).TotalSeconds) + " FPS" + "     Average Drawn Frame Rate: " + Math.Round(drawnFrameCount / (DateTime.UtcNow - totalStartTime).TotalSeconds) + " FPS"; ;
                this.Text = "SequenceL Game Engine | " + lblFrameRate.Text;
                progressFrameRate.Value = Math.Max(Math.Min((int)(count / ((double)FPS) * 100.0), 100), 0);
            }
            if (!firstTick && Math.Abs(count - FPS) > 3)
            {
                currentFPS += (FPS - count) / 2;
            }
            if (firstTick) firstTick = false;
        }

        #endregion

        private void frmMain_FormClosing(object sender, FormClosingEventArgs e)
        {
            bgwEngine.CancelAsync();

            while (bgwEngine.IsBusy)
            {
                Thread.Sleep(100);
                Application.DoEvents();
            }
        }
    }
}
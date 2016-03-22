namespace SL_Game_Engine
{
    partial class frmMain
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(frmMain));
            this.bgwEngine = new System.ComponentModel.BackgroundWorker();
            this.timerFrameRate = new System.Windows.Forms.Timer(this.components);
            this.statusStrip = new System.Windows.Forms.StatusStrip();
            this.progressFrameRate = new System.Windows.Forms.ToolStripProgressBar();
            this.lblFrameRate = new System.Windows.Forms.ToolStripStatusLabel();
            this.picDisplay = new System.Windows.Forms.PictureBox();
            this.openFileDialog = new System.Windows.Forms.OpenFileDialog();
            this.bgwCompile = new System.ComponentModel.BackgroundWorker();
            this.statusStrip.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.picDisplay)).BeginInit();
            this.SuspendLayout();
            // 
            // bgwEngine
            // 
            this.bgwEngine.WorkerReportsProgress = true;
            this.bgwEngine.WorkerSupportsCancellation = true;
            this.bgwEngine.DoWork += new System.ComponentModel.DoWorkEventHandler(this.bgwEngine_DoWork);
            this.bgwEngine.ProgressChanged += new System.ComponentModel.ProgressChangedEventHandler(this.bgwEngine_ProgressChanged);
            this.bgwEngine.RunWorkerCompleted += new System.ComponentModel.RunWorkerCompletedEventHandler(this.bgwEngine_RunWorkerCompleted);
            // 
            // timerFrameRate
            // 
            this.timerFrameRate.Interval = 1000;
            this.timerFrameRate.Tick += new System.EventHandler(this.timerFrameRate_Tick);
            // 
            // statusStrip
            // 
            this.statusStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.progressFrameRate,
            this.lblFrameRate});
            this.statusStrip.Location = new System.Drawing.Point(0, 800);
            this.statusStrip.Name = "statusStrip";
            this.statusStrip.Size = new System.Drawing.Size(1000, 22);
            this.statusStrip.SizingGrip = false;
            this.statusStrip.TabIndex = 0;
            this.statusStrip.Text = "statusStrip1";
            // 
            // progressFrameRate
            // 
            this.progressFrameRate.Name = "progressFrameRate";
            this.progressFrameRate.Size = new System.Drawing.Size(100, 16);
            // 
            // lblFrameRate
            // 
            this.lblFrameRate.Name = "lblFrameRate";
            this.lblFrameRate.Size = new System.Drawing.Size(69, 17);
            this.lblFrameRate.Text = "Frame Rate:";
            // 
            // picDisplay
            // 
            this.picDisplay.BackColor = System.Drawing.Color.White;
            this.picDisplay.Location = new System.Drawing.Point(0, 0);
            this.picDisplay.Name = "picDisplay";
            this.picDisplay.Size = new System.Drawing.Size(1000, 800);
            this.picDisplay.TabIndex = 1;
            this.picDisplay.TabStop = false;
            this.picDisplay.Paint += new System.Windows.Forms.PaintEventHandler(this.picDisplay_Paint);
            this.picDisplay.MouseDown += new System.Windows.Forms.MouseEventHandler(this.picDisplay_MouseDown);
            // 
            // openFileDialog
            // 
            this.openFileDialog.Filter = "SequenceL Files|*.sl|All Files|*.*";
            this.openFileDialog.Title = "Choose your SequenceL Game";
            // 
            // bgwCompile
            // 
            this.bgwCompile.DoWork += new System.ComponentModel.DoWorkEventHandler(this.bgwCompile_DoWork);
            this.bgwCompile.RunWorkerCompleted += new System.ComponentModel.RunWorkerCompletedEventHandler(this.bgwCompile_RunWorkerCompleted);
            // 
            // frmMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1000, 822);
            this.Controls.Add(this.picDisplay);
            this.Controls.Add(this.statusStrip);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.MaximumSize = new System.Drawing.Size(1016, 860);
            this.MinimumSize = new System.Drawing.Size(1016, 726);
            this.Name = "frmMain";
            this.SizeGripStyle = System.Windows.Forms.SizeGripStyle.Hide;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "SequenceL Game Engine";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.frmMain_FormClosing);
            this.Load += new System.EventHandler(this.frmMain_Load);
            this.Shown += new System.EventHandler(this.frmMain_Shown);
            this.KeyDown += new System.Windows.Forms.KeyEventHandler(this.frmMain_KeyDown);
            this.KeyUp += new System.Windows.Forms.KeyEventHandler(this.frmMain_KeyUp);
            this.statusStrip.ResumeLayout(false);
            this.statusStrip.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.picDisplay)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.ComponentModel.BackgroundWorker bgwEngine;
        private System.Windows.Forms.Timer timerFrameRate;
        private System.Windows.Forms.StatusStrip statusStrip;
        private System.Windows.Forms.ToolStripProgressBar progressFrameRate;
        private System.Windows.Forms.ToolStripStatusLabel lblFrameRate;
        private System.Windows.Forms.PictureBox picDisplay;
        private System.Windows.Forms.OpenFileDialog openFileDialog;
        private System.ComponentModel.BackgroundWorker bgwCompile;
    }
}


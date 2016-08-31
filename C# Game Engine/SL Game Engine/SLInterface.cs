using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.Runtime.InteropServices;
using System.Text;
using System.Windows.Forms;
using Microsoft.Win32;

namespace SL_Game_Engine
{

    public static class EaselDLL
    {
        public const string DLL_NAME = @".\EaselGame.dll";

        public static bool HasDll
        {
            get
            {
                return File.Exists(DLL_NAME);
            }
        }

        [DllImport(DLL_NAME, CallingConvention = CallingConvention.Cdecl, EntryPoint = "?initialState@EaselGame@EaselDLL@@SAPEAU_sl_State_0@@H@Z")]
        public static extern IntPtr InitialState(int cores);

        [DllImport(DLL_NAME, CallingConvention = CallingConvention.Cdecl, EntryPoint = "?slTerminate@EaselGame@EaselDLL@@SAXXZ")]
        public static extern void slTerminate();

        [DllImport(DLL_NAME, CallingConvention = CallingConvention.Cdecl, EntryPoint = "?newState@EaselGame@EaselDLL@@SAPEAU_sl_State_0@@_NHHPEADPEAU3@H@Z")]
        public static extern IntPtr NewState(bool clicked, int x, int y, StringBuilder keys, IntPtr inputState, int cores);

        [DllImport(DLL_NAME, CallingConvention = CallingConvention.Cdecl, EntryPoint = "?sounds@EaselGame@EaselDLL@@SAPEAV?$Sequence@V?$Sequence@D@@@@_NHHPEADPEAU_sl_State_0@@H@Z")]
        public static extern IntPtr Sounds(bool clicked, int x, int y, StringBuilder keys, IntPtr inputState, int cores);

        [DllImport(DLL_NAME, CallingConvention = CallingConvention.Cdecl, EntryPoint = "?getSoundsCount@EaselGame@EaselDLL@@SAHPEAV?$Sequence@V?$Sequence@D@@@@@Z")]
        public static extern int GetSoundCount(IntPtr soundSequence);

        [DllImport(DLL_NAME, CallingConvention = CallingConvention.Cdecl, EntryPoint = "?getSound@EaselGame@EaselDLL@@SAXPEAV?$Sequence@V?$Sequence@D@@@@HPEAD@Z")]
        public static extern void GetSound(IntPtr soundSequence, int index, StringBuilder textOut);

        [DllImport(DLL_NAME, CallingConvention = CallingConvention.Cdecl, EntryPoint = "?freeSounds@EaselGame@EaselDLL@@SAXPEAV?$Sequence@V?$Sequence@D@@@@@Z")]
        public static extern void FreeSounds(IntPtr soundSequence);

        [DllImport(DLL_NAME, CallingConvention = CallingConvention.Cdecl, EntryPoint = "?images@EaselGame@EaselDLL@@SAPEAV?$Sequence@U_sl_Image_0@@@@PEAU_sl_State_0@@H@Z")]
        public static extern IntPtr Images(IntPtr inputState, int cores);

        [DllImport(DLL_NAME, CallingConvention = CallingConvention.Cdecl, EntryPoint = "?getImagesCount@EaselGame@EaselDLL@@SAHPEAV?$Sequence@U_sl_Image_0@@@@@Z")]
        public static extern int GetImageCount(IntPtr imageSequence);

        [DllImport(DLL_NAME, CallingConvention = CallingConvention.Cdecl, EntryPoint = "?getImageKind@EaselGame@EaselDLL@@SAHPEAV?$Sequence@U_sl_Image_0@@@@H@Z")]
        public static extern int GetImageKind(IntPtr imageSequence, int index);

        [DllImport(DLL_NAME, CallingConvention = CallingConvention.Cdecl, EntryPoint = "?getImageEnd1X@EaselGame@EaselDLL@@SAHPEAV?$Sequence@U_sl_Image_0@@@@H@Z")]
        public static extern int GetImageEnd1X(IntPtr imageSequence, int index);

        [DllImport(DLL_NAME, CallingConvention = CallingConvention.Cdecl, EntryPoint = "?getImageEnd1Y@EaselGame@EaselDLL@@SAHPEAV?$Sequence@U_sl_Image_0@@@@H@Z")]
        private static extern int GetImageEnd1YDLL(IntPtr imageSequence, int index);

        public static int GetImageEnd1Y(IntPtr imageSequence, int index)
        {
            return 800 - GetImageEnd1YDLL(imageSequence, index);
        }

        [DllImport(DLL_NAME, CallingConvention = CallingConvention.Cdecl, EntryPoint = "?getImageEnd2X@EaselGame@EaselDLL@@SAHPEAV?$Sequence@U_sl_Image_0@@@@H@Z")]
        public static extern int GetImageEnd2X(IntPtr imageSequence, int index);

        [DllImport(DLL_NAME, CallingConvention = CallingConvention.Cdecl, EntryPoint = "?getImageEnd2Y@EaselGame@EaselDLL@@SAHPEAV?$Sequence@U_sl_Image_0@@@@H@Z")]
        public static extern int GetImageEnd2YDLL(IntPtr imageSequence, int index);

        public static int GetImageEnd2Y(IntPtr imageSequence, int index)
        {
            return 800 - GetImageEnd2YDLL(imageSequence, index);
        }

        [DllImport(DLL_NAME, CallingConvention = CallingConvention.Cdecl, EntryPoint = "?getImageEnd3X@EaselGame@EaselDLL@@SAHPEAV?$Sequence@U_sl_Image_0@@@@H@Z")]
        public static extern int GetImageEnd3X(IntPtr imageSequence, int index);

        [DllImport(DLL_NAME, CallingConvention = CallingConvention.Cdecl, EntryPoint = "?getImageEnd3Y@EaselGame@EaselDLL@@SAHPEAV?$Sequence@U_sl_Image_0@@@@H@Z")]
        public static extern int GetImageEnd3YDLL(IntPtr imageSequence, int index);

        public static int GetImageEnd3Y(IntPtr imageSequence, int index)
        {
            return 800 - GetImageEnd3YDLL(imageSequence, index);
        }

        [DllImport(DLL_NAME, CallingConvention = CallingConvention.Cdecl, EntryPoint = "?getImageR@EaselGame@EaselDLL@@SAHPEAV?$Sequence@U_sl_Image_0@@@@H@Z")]
        public static extern int GetImageR(IntPtr imageSequence, int index);

        [DllImport(DLL_NAME, CallingConvention = CallingConvention.Cdecl, EntryPoint = "?getImageG@EaselGame@EaselDLL@@SAHPEAV?$Sequence@U_sl_Image_0@@@@H@Z")]
        public static extern int GetImageG(IntPtr imageSequence, int index);

        [DllImport(DLL_NAME, CallingConvention = CallingConvention.Cdecl, EntryPoint = "?getImageB@EaselGame@EaselDLL@@SAHPEAV?$Sequence@U_sl_Image_0@@@@H@Z")]
        public static extern int GetImageB(IntPtr imageSequence, int index);

        [DllImport(DLL_NAME, CallingConvention = CallingConvention.Cdecl, EntryPoint = "?getImageCenterX@EaselGame@EaselDLL@@SAHPEAV?$Sequence@U_sl_Image_0@@@@H@Z")]
        public static extern int GetImageCenterX(IntPtr imageSequence, int index);

        [DllImport(DLL_NAME, CallingConvention = CallingConvention.Cdecl, EntryPoint = "?getImageCenterY@EaselGame@EaselDLL@@SAHPEAV?$Sequence@U_sl_Image_0@@@@H@Z")]
        public static extern int GetImageCenterYDLL(IntPtr imageSequence, int index);

        public static int GetImageCenterY(IntPtr imageSequence, int index)
        {
            return 800 - GetImageCenterYDLL(imageSequence, index);
        }

        [DllImport(DLL_NAME, CallingConvention = CallingConvention.Cdecl, EntryPoint = "?getImageRadius@EaselGame@EaselDLL@@SAHPEAV?$Sequence@U_sl_Image_0@@@@H@Z")]
        public static extern int GetImageRadius(IntPtr imageSequence, int index);

        [DllImport(DLL_NAME, CallingConvention = CallingConvention.Cdecl, EntryPoint = "?getImageHeight@EaselGame@EaselDLL@@SAHPEAV?$Sequence@U_sl_Image_0@@@@H@Z")]
        public static extern int GetImageHeight(IntPtr imageSequence, int index);

        [DllImport(DLL_NAME, CallingConvention = CallingConvention.Cdecl, EntryPoint = "?getImageWidth@EaselGame@EaselDLL@@SAHPEAV?$Sequence@U_sl_Image_0@@@@H@Z")]
        public static extern int GetImageWidth(IntPtr imageSequence, int index);

        [DllImport(DLL_NAME, CallingConvention = CallingConvention.Cdecl, EntryPoint = "?getImageText@EaselGame@EaselDLL@@SAHPEAV?$Sequence@U_sl_Image_0@@@@HPEAD@Z")]
        public static extern int GetImageText(IntPtr imageSequence, int index, StringBuilder textOut);

        [DllImport(DLL_NAME, CallingConvention = CallingConvention.Cdecl, EntryPoint = "?getGraphicLocation@EaselGame@EaselDLL@@SAHPEAV?$Sequence@U_sl_Image_0@@@@HPEAD@Z")]
        public static extern int GetGraphicLocation(IntPtr imageSequence, int index, StringBuilder textOut);

        [DllImport(DLL_NAME, CallingConvention = CallingConvention.Cdecl, EntryPoint = "?freeState@EaselGame@EaselDLL@@SAXPEAU_sl_State_0@@@Z")]
        public static extern void FreeState(IntPtr state);

        [DllImport(DLL_NAME, CallingConvention = CallingConvention.Cdecl, EntryPoint = "?freeImages@EaselGame@EaselDLL@@SAXPEAV?$Sequence@U_sl_Image_0@@@@@Z")]
        public static extern void FreeImages(IntPtr images);
    }

    static class SLInterface
    {
        const int STRINGSIZE = 512;
        public static StringBuilder output = new StringBuilder(STRINGSIZE);
        static IntPtr state;

        public static List<SLImage> getImages()
        {
            List<SLImage> retval = new List<SLImage>();

            IntPtr images = EaselDLL.Images(state, 0);

            int imagesCount = EaselDLL.GetImageCount(images);

            for (int i = 1; i <= imagesCount; i++)
            {
                retval.Add(new SLImage(images, i));
            }

            EaselDLL.FreeImages(images);

            return retval;
        }

        public static void getInitialState()
        {
            state = EaselDLL.InitialState(0);
        }

        public static void getNewState(bool clicked, int x, int y, string keys)
        {
            StringBuilder inputKeys = new StringBuilder(keys);
            state = EaselDLL.NewState(clicked, x, y, inputKeys, state, 0);
        }

        public static List<string> getSounds(bool clicked, int x, int y, string keys)
        {
            List<string> retval = new List<string>();
            StringBuilder inputKeys = new StringBuilder(keys);

            IntPtr sounds = EaselDLL.Sounds(clicked, x, y, inputKeys, state, 0);

            for (int i = 1; i <= EaselDLL.GetSoundCount(sounds); i++)
            {
                EaselDLL.GetSound(sounds, i, output);
                retval.Add(output.ToString());
            }

            EaselDLL.FreeSounds(sounds);

            return retval;
        }
    }

    public enum Sounds { Ding = 1, Bang = 2, Boing = 3, Clap = 4, Click = 5 };

    class SLImage
    {
        public enum Kinds { Segment = 1, Circle = 2, Text = 4, Disc = 3, Triangle = 5, Graphic = 6 };

        public Kinds Kind;
        public Point End1;
        public Point End2;
        public Point End3;
        public Point Center;
        public int Radius;
        public int Height;
        public int Width;
        public Color Color;
        public string Message;
        public string FileLocation;

        private bool hasEnd1(Kinds kind) { return kind == Kinds.Segment || kind == Kinds.Triangle; }

        private bool hasEnd2(Kinds kind) { return kind == Kinds.Segment || kind == Kinds.Triangle; }

        private bool hasEnd3(Kinds kind) { return kind == Kinds.Triangle; }

        private bool hasCenter(Kinds kind) { return kind == Kinds.Circle || kind == Kinds.Disc || kind == Kinds.Graphic || kind == Kinds.Text; }

        private bool hasRadius(Kinds kind) { return kind == Kinds.Circle || kind == Kinds.Disc; }

        private bool hasHeight(Kinds kind) { return kind == Kinds.Graphic || kind == Kinds.Text; }

        private bool hasWidth(Kinds kind) { return kind == Kinds.Graphic; }

        private bool hasColor(Kinds kind) { return kind == Kinds.Circle || kind == Kinds.Disc || kind == Kinds.Segment || kind == Kinds.Triangle || kind == Kinds.Text; }

        private bool hasMessage(Kinds kind) { return kind == Kinds.Text; }

        private bool hasFileLocation(Kinds kind) { return kind == Kinds.Graphic; }

        public SLImage(Kinds kind, Point end1, Point end2, Point end3, Point center, int radius, int Height, int Width, Color color, string message, string fileLocation)
        {
            this.Kind = kind;
            this.End1 = end1;
            this.End2 = end2;
            this.End3 = end3;
            this.Center = center;
            this.Radius = radius;
            this.Height = Height;
            this.Width = Width;
            this.Color = color;
            this.Message = message;
            this.FileLocation = fileLocation;
        }

        public SLImage(IntPtr images, int i)
        {
            this.Kind = (SLImage.Kinds)EaselDLL.GetImageKind(images, i);

            this.End1 = hasEnd1(this.Kind) ? new Point(EaselDLL.GetImageEnd1X(images, i), EaselDLL.GetImageEnd1Y(images, i)) : new Point();
            this.End2 = hasEnd2(this.Kind) ? new Point(EaselDLL.GetImageEnd2X(images, i), EaselDLL.GetImageEnd2Y(images, i)) : new Point();
            this.End3 = hasEnd3(this.Kind) ? new Point(EaselDLL.GetImageEnd3X(images, i), EaselDLL.GetImageEnd3Y(images, i)) : new Point();
            this.Center = hasCenter(this.Kind) ? new Point(EaselDLL.GetImageCenterX(images, i), EaselDLL.GetImageCenterY(images, i)) : new Point();
            this.Radius = hasRadius(this.Kind) ? EaselDLL.GetImageRadius(images, i) : 0;
            this.Height = hasHeight(this.Kind) ? EaselDLL.GetImageHeight(images, i) : 0;
            this.Width = hasWidth(this.Kind) ? EaselDLL.GetImageWidth(images, i) : 0;
            this.Color = hasColor(this.Kind) ? Color.FromArgb(EaselDLL.GetImageR(images, i), EaselDLL.GetImageG(images, i), EaselDLL.GetImageB(images, i)) : Color.Black;

            this.Message = "";
            if (hasMessage(this.Kind))
            {
                EaselDLL.GetImageText(images, i, SLInterface.output);
                this.Message = SLInterface.output.ToString();
            }

            this.FileLocation = "";
            if (hasFileLocation(this.Kind))
            {
                EaselDLL.GetGraphicLocation(images, i, SLInterface.output);
                this.FileLocation = SLInterface.output.ToString();
            }
        }
    }

    public static class Execution
    {
        private static string Execute(string fileLocation, string commandLine, int Timeout)
        {
            if (!File.Exists(fileLocation))
            {
                throw new FileNotFoundException();
            }

            StreamReader outputReader = null;
            StreamReader errorReader = null;
            string displayText = "";
            string stdOut = "";
            string stdErr = "";

            try
            {
                ProcessStartInfo psi = new ProcessStartInfo(fileLocation, commandLine);

                psi.ErrorDialog = false;
                psi.UseShellExecute = false;
                psi.RedirectStandardError = true;
                psi.RedirectStandardInput = true;
                psi.RedirectStandardOutput = true;
                psi.CreateNoWindow = true;

                System.Diagnostics.Process proc = new System.Diagnostics.Process();
                proc.StartInfo = psi;
                bool started = proc.Start();
                if (started)
                {
                    outputReader = proc.StandardOutput;
                    errorReader = proc.StandardError;
                    DateTime start = DateTime.Now;
                    while (!proc.HasExited)
                    {
                        System.Threading.Thread.Sleep(50);
                        //Application.DoEvents();
                        if (Timeout > 0 && (DateTime.Now - start).TotalSeconds > Timeout)
                        {
                            if (!proc.HasExited)
                            {
                                proc.Kill();

                                if (outputReader != null)
                                {
                                    outputReader.Close();
                                }
                                if (errorReader != null)
                                {
                                    errorReader.Close();
                                }

                                return "Error";
                            }
                        }
                    }

                    stdOut = outputReader.ReadToEnd().Trim();
                    stdErr = errorReader.ReadToEnd().Trim();

                    if (stdErr.Trim().Length > 0)
                    {
                        //Gridworld_Simulation.Utilities.ShowError(stdErr, "Error Planning!");
                    }

                    displayText += stdOut + Environment.NewLine + stdErr;
                }
                try
                {
                    if (!proc.HasExited)
                    {
                        displayText = "Error";
                        proc.Kill();
                    }
                }
                catch
                {

                }
            }
            catch (Exception e)
            {
                throw e;
            }
            finally
            {
                if (outputReader != null)
                {
                    outputReader.Close();
                }
                if (errorReader != null)
                {
                    errorReader.Close();
                }
            }

            return displayText;
        }

        private static string slcLocation
        {
            get
            {
                return Path.Combine(Environment.GetEnvironmentVariable("SL_HOME"), @"bin\slc.exe");
            }
        }

        private static string slDirectory
        {
            get
            {
                return Environment.GetEnvironmentVariable("SL_HOME");
            }
        }

        public static bool HasSequenceL
        {
            get
            {
                return File.Exists(slcLocation);
            }
        }

        private static string vsLocation
        {
            get
            {
                string installationPath = "";

                if (VSVersion == "vs12")
                {
                    installationPath = (string)Registry.GetValue(baseVSLocation + "12.0\\", "InstallDir", null);
                }
                else if (VSVersion == "vs11")
                {
                    installationPath = (string)Registry.GetValue(baseVSLocation + "11.0\\", "InstallDir", null);
                }
                else if (VSVersion == "vs10")
                {
                    installationPath = (string)Registry.GetValue(baseVSLocation + "10.0\\", "InstallDir", null);
                }

                return Path.GetFullPath(Path.Combine(installationPath, @"..\..\VC\vcvarsall.bat"));
            }

        }

        private static string baseVSLocation
        {
            get
            {
                if (Environment.Is64BitOperatingSystem)
                {
                    return "HKEY_LOCAL_MACHINE\\SOFTWARE\\Wow6432Node\\Microsoft\\VisualStudio\\";
                }
                else
                {
                    return "HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\VisualStudio\\";
                }
            }
        }

        public static string VSVersion
        {
            get
            {
                if ((string)Registry.GetValue(baseVSLocation + "12.0\\", "InstallDir", "") != "")
                {
                    return "vs12";
                }
                else if ((string)Registry.GetValue(baseVSLocation + "11.0\\", "InstallDir", "") != "")
                {
                    return "vs11";
                }
                else if ((string)Registry.GetValue(baseVSLocation + "10.0\\", "InstallDir", "") != "")
                {
                    return "vs10";
                }
                else
                {
                    return "none";
                }
            }
        }

        public static bool HasVS10
        {
            get
            {
                return File.Exists(vsLocation);
            }
        }

        public static void Compile(string sequencelFile)
        {
            string mainFile = Path.Combine(Path.GetTempPath(), "main");

            //string slcParametrs = "-c \"" + sequencelFile + "\" -f \"initialState()\" -f \"images(State(0))\" -f \"newState(Input(0), State(0))\" -f \"sounds(Input(0), State(0))\" -o \"" + mainFile + "\" --debug --parallel --no_debug_print --rtc=0";
            string slcParametrs = "-c \"" + sequencelFile + "\" -f \"initialState()\" -f \"images(State(0))\" -f \"newState(Input(0), State(0))\" -f \"sounds(Input(0), State(0))\" -o \"" + mainFile + "\" --parallel --no_debug_print --rtc=0";

            string mainDriverFile = Path.ChangeExtension(Path.GetTempFileName(), "cpp");
            File.WriteAllText(mainDriverFile, GetResourceTextFile("mainDriver.cpp"));

            File.WriteAllText(Path.Combine(Path.GetTempPath(), "LibraryTest.h"), GetResourceTextFile("LibraryTest.h"));

            string dllOut = Path.Combine(Path.GetDirectoryName(Application.ExecutablePath), EaselDLL.DLL_NAME);

            string compileScript = @"@echo off" + Environment.NewLine +
                                    "cd %temp%" + Environment.NewLine +
                                    "call \"" + vsLocation + "\" x64" + Environment.NewLine +
                                    "cl /c /EHs /MD /Zi \"/I" + slDirectory + "\\include\" /nologo /Fo" + Path.GetFileName(Path.ChangeExtension(mainDriverFile, "obj")) + " \"" + mainDriverFile + "\"" + Environment.NewLine +
                                    "cl /c /EHs /MD /Zi \"/I" + slDirectory + "\\include\" /nologo /Fo" + Path.GetFileName(Path.ChangeExtension(mainFile, "obj")) + " \"" + Path.ChangeExtension(mainFile, "cpp") + "\" " + Environment.NewLine +
                                    "link /DLL /nologo \"/libpath:" + slDirectory + "\\lib\"  \"/libpath:" + slDirectory + "\\lib\\" + VSVersion + "\" /OUT:\"" + dllOut + "\" " + Path.GetFileName(Path.ChangeExtension(mainDriverFile, "obj")) + " " + Path.GetFileName(Path.ChangeExtension(mainFile, "obj")) + " slrt.lib tbb.lib tbbmalloc.lib ";

            string compileBatchFile = Path.ChangeExtension(Path.GetTempFileName(), "bat");

            File.WriteAllText(compileBatchFile, compileScript);

            string slCompileResult = Execute(slcLocation, slcParametrs, 60);

            string dllCompileResult = Execute(compileBatchFile, "", 60);

            if (slCompileResult.Trim().Length > 0)
            {
                MessageBox.Show(slCompileResult);
                Application.Exit();
            }

            if (!dllCompileResult.Trim().EndsWith("Finished generating code"))
            {
                MessageBox.Show(dllCompileResult);
                Application.Exit();
            }
        }

        public static string GetResourceTextFile(string filename)
        {
            string result = string.Empty;

            using (Stream stream = System.Reflection.Assembly.GetExecutingAssembly().GetManifestResourceStream("SL_Game_Engine." + filename))
            {
                using (StreamReader sr = new StreamReader(stream))
                {
                    result = sr.ReadToEnd();
                }
            }
            return result;
        }
    }
}

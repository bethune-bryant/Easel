using System;
using System.Collections.Generic;
using System.IO;
using System.Runtime.InteropServices;
using System.Text;

namespace SL_Game_Engine
{
    public static class SoundEngine
    {
        private static Dictionary<string, MP3Player> players = InitializeSounds();

        private static void CopyStream(Stream input, Stream output)
        {
            // Insert null checking here for production
            byte[] buffer = new byte[8192];

            int bytesRead;
            while ((bytesRead = input.Read(buffer, 0, buffer.Length)) > 0)
            {
                output.Write(buffer, 0, bytesRead);
            }
        }

        private static Dictionary<string, MP3Player> InitializeSounds()
        {
            Dictionary<string, MP3Player> retval = new Dictionary<string, MP3Player>();

            string ding = Path.ChangeExtension(Path.GetTempFileName(), "wav");
            using (Stream input = Properties.Resources.ding)
            using (Stream output = File.Create(ding))
            {
                CopyStream(input, output);
            }
            retval.Add("ding", new MP3Player(ding));

            string bang = Path.ChangeExtension(Path.GetTempFileName(), "wav");
            using (Stream input = Properties.Resources.bang)
            using (Stream output = File.Create(bang))
            {
                CopyStream(input, output);
            }
            retval.Add("bang", new MP3Player(bang));

            string boing = Path.ChangeExtension(Path.GetTempFileName(), "wav");
            using (Stream input = Properties.Resources.boing)
            using (Stream output = File.Create(boing))
            {
                CopyStream(input, output);
            }
            retval.Add("boing", new MP3Player(boing));

            string clap = Path.ChangeExtension(Path.GetTempFileName(), "wav");
            using (Stream input = Properties.Resources.clap)
            using (Stream output = File.Create(clap))
            {
                CopyStream(input, output);
            }
            retval.Add("clap", new MP3Player(clap));

            string click = Path.ChangeExtension(Path.GetTempFileName(), "wav");
            using (Stream input = Properties.Resources.click)
            using (Stream output = File.Create(click))
            {
                CopyStream(input, output);
            }
            retval.Add("click", new MP3Player(click));

            return retval;
        }

        public static void PlaySound(string fileName)
        {
            if (!players.ContainsKey(fileName))
            {
                if (System.IO.File.Exists(fileName))
                {
                    players.Add(fileName, new MP3Player(fileName));

                }
            }
            if (players.ContainsKey(fileName))
            {
                players[fileName].Play();
            }
        }
    }

    public class MP3Player
    {
        private string Pcommand, FName, alias;
        public bool Playing;
        private bool Opened, Paused, Loop,
                     MutedAll, MutedLeft, MutedRight;
        private int rVolume, lVolume, aVolume,
                    tVolume, bVolume, VolBalance;
        //private ulong Lng;
        private long Err;
        private static int counter = 0;

        [DllImport("winmm.dll")]
        private static extern long mciSendString(string strCommand,
                StringBuilder strReturn, int iReturnLength,
                IntPtr hwndCallback);

        public MP3Player()
        {
            Opened = false;
            Pcommand = "";
            FName = "";
            Playing = false;
            Paused = false;
            Loop = false;
            MutedAll = MutedLeft = MutedRight = false;
            rVolume = lVolume = aVolume =
                      tVolume = bVolume = 1000;
            //Lng = 0;
            VolBalance = 0;
            Err = 0;
            counter++;
            alias = "alias" + counter.ToString();
        }

        public MP3Player(string soundFile)
            : this()
        {
            this.Open(soundFile);
        }

        ~MP3Player()
        {
        }

        #region Volume
        public bool MuteAll
        {
            get
            {
                return MutedAll;
            }
            set
            {
                MutedAll = value;
                if (MutedAll)
                {
                    Pcommand = "setaudio " + alias + " off";
                    if ((Err = mciSendString(Pcommand, null, 0, IntPtr.Zero)) != 0)
                        OnError(new ErrorEventArgs(Err));
                }
                else
                {
                    Pcommand = "setaudio " + alias + " on";
                    if ((Err = mciSendString(Pcommand, null, 0, IntPtr.Zero)) != 0)
                        OnError(new ErrorEventArgs(Err));
                }
            }

        }

        public bool MuteLeft
        {
            get
            {
                return MutedLeft;
            }
            set
            {
                MutedLeft = value;
                if (MutedLeft)
                {
                    Pcommand = "setaudio " + alias + " left off";
                    if ((Err = mciSendString(Pcommand, null, 0, IntPtr.Zero)) != 0)
                        OnError(new ErrorEventArgs(Err));
                }
                else
                {
                    Pcommand = "setaudio " + alias + " left on";
                    if ((Err = mciSendString(Pcommand, null, 0, IntPtr.Zero)) != 0)
                        OnError(new ErrorEventArgs(Err));
                }
            }

        }

        public bool MuteRight
        {
            get
            {
                return MutedRight;
            }
            set
            {
                MutedRight = value;
                if (MutedRight)
                {
                    Pcommand = "setaudio " + alias + " right off";
                    if ((Err = mciSendString(Pcommand, null, 0, IntPtr.Zero)) != 0)
                        OnError(new ErrorEventArgs(Err));
                }
                else
                {
                    Pcommand = "setaudio " + alias + " right on";
                    if ((Err = mciSendString(Pcommand, null, 0, IntPtr.Zero)) != 0)
                        OnError(new ErrorEventArgs(Err));
                }
            }

        }

        public int VolumeAll
        {
            get
            {
                return aVolume;
            }
            set
            {
                if (Opened && (value >= 0 && value <= 1000))
                {
                    aVolume = value;
                    Pcommand = String.Format("setaudio " + alias + "" +
                               " volume to {0}", aVolume);
                    if ((Err = mciSendString(Pcommand, null, 0,
                                          IntPtr.Zero)) != 0)
                        OnError(new ErrorEventArgs(Err));
                }
            }
        }

        public int VolumeLeft
        {
            get
            {
                return lVolume;
            }
            set
            {
                if (Opened && (value >= 0 && value <= 1000))
                {
                    lVolume = value;
                    Pcommand = String.Format("setaudio " + alias + "" +
                               " left volume to {0}", lVolume);
                    if ((Err = mciSendString(Pcommand, null, 0,
                                           IntPtr.Zero)) != 0)
                        OnError(new ErrorEventArgs(Err));
                }
            }
        }

        public int VolumeRight
        {
            get
            {
                return rVolume;
            }
            set
            {
                if (Opened && (value >= 0 && value <= 1000))
                {
                    rVolume = value;
                    Pcommand = String.Format("setaudio" +
                               " " + alias + " right volume to {0}", rVolume);
                    if ((Err = mciSendString(Pcommand, null, 0, IntPtr.Zero)) != 0)
                        OnError(new ErrorEventArgs(Err));
                }
            }
        }

        public int VolumeTreble
        {
            get
            {
                return tVolume;
            }
            set
            {
                if (Opened && (value >= 0 && value <= 1000))
                {
                    tVolume = value;
                    Pcommand = String.Format("setaudio " + alias + "" +
                                             " treble to {0}", tVolume);
                    if ((Err = mciSendString(Pcommand, null, 0, IntPtr.Zero)) != 0)
                        OnError(new ErrorEventArgs(Err));
                }
            }
        }

        public int VolumeBass
        {
            get
            {
                return bVolume;
            }
            set
            {
                if (Opened && (value >= 0 && value <= 1000))
                {
                    bVolume = value;
                    Pcommand = String.Format("setaudio " + alias + " bass to {0}",
                                             bVolume);
                    if ((Err = mciSendString(Pcommand, null, 0, IntPtr.Zero)) != 0)
                        OnError(new ErrorEventArgs(Err));
                }
            }
        }

        public int Balance
        {
            get
            {
                return VolBalance;
            }
            set
            {
                if (Opened && (value >= -1000 && value <= 1000))
                {
                    VolBalance = value;
                    if (value < 0)
                    {
                        Pcommand = "setaudio " + alias + " left volume to 1000";
                        if ((Err = mciSendString(Pcommand, null, 0, IntPtr.Zero)) != 0)
                            OnError(new ErrorEventArgs(Err));
                        Pcommand = String.Format("setaudio " + alias + " right" +
                                                 " volume to {0}", 1000 + value);
                        if ((Err = mciSendString(Pcommand, null, 0, IntPtr.Zero)) != 0)
                            OnError(new ErrorEventArgs(Err));
                    }
                    else
                    {
                        Pcommand = "setaudio " + alias + " right volume to 1000";
                        if ((Err = mciSendString(Pcommand, null, 0, IntPtr.Zero)) != 0)
                            OnError(new ErrorEventArgs(Err));
                        Pcommand = String.Format("setaudio " + alias + "" +
                                   " left volume to {0}", 1000 - value);
                        if ((Err = mciSendString(Pcommand, null, 0, IntPtr.Zero)) != 0)
                            OnError(new ErrorEventArgs(Err));
                    }
                }
            }
        }
        #endregion

        #region Main Functions

        public string FileName
        {
            get
            {
                return FName;
            }
        }

        public bool Looping
        {
            get
            {
                return Loop;
            }
            set
            {
                Loop = value;
            }
        }
        /*
        public void Seek(ulong Millisecs)
        {
            if (Opened && Millisecs <= Lng)
            {
                if (Playing)
                {
                    if (Paused)
                    {
                        Pcommand = String.Format("seek " + alias + " to {0}", Millisecs);
                        if ((Err = mciSendString(Pcommand, null, 0, IntPtr.Zero)) != 0)
                            OnError(new ErrorEventArgs(Err));
                    }
                    else
                    {
                        Pcommand = String.Format("seek " + alias + " to {0}", Millisecs);
                        if ((Err = mciSendString(Pcommand, null, 0, IntPtr.Zero)) != 0)
                            OnError(new ErrorEventArgs(Err));
                        Pcommand = "play " + alias + "";
                        if ((Err = mciSendString(Pcommand, null, 0, IntPtr.Zero)) != 0)
                            OnError(new ErrorEventArgs(Err));
                    }
                }
            }
        }
        */
        private void CalculateLength()
        {
            StringBuilder str = new StringBuilder(128);
            mciSendString("status " + alias + " length", str, 128, IntPtr.Zero);
            //Lng = Convert.ToUInt64(str.ToString());
        }
        /*
        public ulong AudioLength
        {
            get
            {
                if (Opened) return Lng;
                else return 0;
            }
        }
        */
        public void Close()
        {
            if (Opened)
            {
                Pcommand = "close " + alias + "";
                if ((Err = mciSendString(Pcommand, null, 0, IntPtr.Zero)) != 0)
                    OnError(new ErrorEventArgs(Err));
                Opened = false;
                Playing = false;
                Paused = false;
                OnCloseFile(new CloseFileEventArgs());
            }
        }

        public void Open(string sFileName)
        {
            if (!Opened)
            {
                Pcommand = "open \"" + sFileName +
                           "\" type waveaudio alias " + alias + "";
                if ((Err = mciSendString(Pcommand, null, 0, IntPtr.Zero)) != 0)
                    OnError(new ErrorEventArgs(Err));
                FName = sFileName;
                Opened = true;
                Playing = false;
                Paused = false;
                Pcommand = "set " + alias + " time format milliseconds";
                if ((Err = mciSendString(Pcommand, null, 0, IntPtr.Zero)) != 0)
                    OnError(new ErrorEventArgs(Err));
                Pcommand = "set " + alias + " seek exactly on";
                if ((Err = mciSendString(Pcommand, null, 0, IntPtr.Zero)) != 0)
                    OnError(new ErrorEventArgs(Err));
                CalculateLength();
                OnOpenFile(new OpenFileEventArgs(sFileName));
            }
            else
            {
                this.Close();
                this.Open(sFileName);
            }
        }

        public void Play()
        {
            if (Opened)
            {
                if (!Playing)
                {
                    Playing = true;
                    Pcommand = "play " + alias + "";
                    if (Loop) Pcommand += " REPEAT";
                    if ((Err = mciSendString(Pcommand, null, 0, IntPtr.Zero)) != 0)
                        OnError(new ErrorEventArgs(Err));
                    OnPlayFile(new PlayFileEventArgs());
                }
                else
                {
                    if (!Paused)
                    {
                        Pcommand = "seek " + alias + " to start";
                        if ((Err = mciSendString(Pcommand, null, 0, IntPtr.Zero)) != 0)
                            OnError(new ErrorEventArgs(Err));
                        Pcommand = "play " + alias + "";
                        if ((Err = mciSendString(Pcommand, null, 0, IntPtr.Zero)) != 0)
                            OnError(new ErrorEventArgs(Err));
                        OnPlayFile(new PlayFileEventArgs());
                    }
                    else
                    {
                        Paused = false;
                        Pcommand = "play " + alias + "";
                        if ((Err = mciSendString(Pcommand, null, 0, IntPtr.Zero)) != 0)
                            OnError(new ErrorEventArgs(Err));
                        OnPlayFile(new PlayFileEventArgs());
                    }
                }
            }
        }

        public void Pause()
        {
            if (Opened)
            {
                if (!Paused)
                {
                    Paused = true;
                    Pcommand = "pause " + alias + "";
                    if ((Err = mciSendString(Pcommand, null, 0, IntPtr.Zero)) != 0)
                        OnError(new ErrorEventArgs(Err));
                    OnPauseFile(new PauseFileEventArgs());
                }
                else
                {
                    Paused = false;
                    Pcommand = "play " + alias + "";
                    if ((Err = mciSendString(Pcommand, null, 0, IntPtr.Zero)) != 0)
                        OnError(new ErrorEventArgs(Err));
                    OnPlayFile(new PlayFileEventArgs());
                }
            }
        }

        public void Stop()
        {
            if (Opened && Playing)
            {
                Playing = false;
                Paused = false;
                Pcommand = "seek " + alias + " to start";
                if ((Err = mciSendString(Pcommand, null, 0, IntPtr.Zero)) != 0)
                    OnError(new ErrorEventArgs(Err));
                Pcommand = "stop " + alias + "";
                if ((Err = mciSendString(Pcommand, null, 0, IntPtr.Zero)) != 0)
                    OnError(new ErrorEventArgs(Err));
                OnStopFile(new StopFileEventArgs());
            }
        }

        public ulong CurrentPosition
        {
            get
            {
                if (Opened && Playing)
                {
                    StringBuilder s = new StringBuilder(128);
                    Pcommand = "status " + alias + " position";
                    if ((Err = mciSendString(Pcommand, s, 128, IntPtr.Zero)) != 0)
                        OnError(new ErrorEventArgs(Err));
                    return Convert.ToUInt64(s.ToString());
                }
                else return 0;
            }
        }

        #endregion

        #region Event Handling

        public delegate void OpenFileEventHandler(Object sender,
                             OpenFileEventArgs oea);

        public delegate void PlayFileEventHandler(Object sender,
                             PlayFileEventArgs pea);

        public delegate void PauseFileEventHandler(Object sender,
                             PauseFileEventArgs paea);

        public delegate void StopFileEventHandler(Object sender,
                                         StopFileEventArgs sea);

        public delegate void CloseFileEventHandler(Object sender,
                                         CloseFileEventArgs cea);

        public delegate void ErrorEventHandler(Object sender,
                                         ErrorEventArgs eea);

        public event OpenFileEventHandler OpenFile;

        public event PlayFileEventHandler PlayFile;

        public event PauseFileEventHandler PauseFile;

        public event StopFileEventHandler StopFile;

        public event CloseFileEventHandler CloseFile;

        public event ErrorEventHandler Error;

        protected virtual void OnOpenFile(OpenFileEventArgs oea)
        {
            if (OpenFile != null) OpenFile(this, oea);
        }

        protected virtual void OnPlayFile(PlayFileEventArgs pea)
        {
            if (PlayFile != null) PlayFile(this, pea);
        }

        protected virtual void OnPauseFile(PauseFileEventArgs paea)
        {
            if (PauseFile != null) PauseFile(this, paea);
        }

        protected virtual void OnStopFile(StopFileEventArgs sea)
        {
            if (StopFile != null) StopFile(this, sea);
        }

        protected virtual void OnCloseFile(CloseFileEventArgs cea)
        {
            if (CloseFile != null) CloseFile(this, cea);
        }

        protected virtual void OnError(ErrorEventArgs eea)
        {
            if (Error != null) Error(this, eea);
        }


    }

    public class OpenFileEventArgs : EventArgs
    {
        public OpenFileEventArgs(string filename)
        {
            this.FileName = filename;
        }
        public readonly string FileName;
    }

    public class PlayFileEventArgs : EventArgs
    {
        public PlayFileEventArgs()
        {

        }
    }

    public class PauseFileEventArgs : EventArgs
    {
        public PauseFileEventArgs()
        {
        }
    }

    public class StopFileEventArgs : EventArgs
    {
        public StopFileEventArgs()
        {
        }
    }

    public class CloseFileEventArgs : EventArgs
    {
        public CloseFileEventArgs()
        {
        }
    }

    public class ErrorEventArgs : EventArgs
    {
        public ErrorEventArgs(long Err)
        {
            this.ErrNum = Err;
        }

        public readonly long ErrNum;
    }
        #endregion
}

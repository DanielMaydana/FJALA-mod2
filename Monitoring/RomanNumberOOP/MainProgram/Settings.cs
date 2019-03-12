﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Configuration;
using System.Threading.Tasks;

namespace MainProgram
{
    public sealed class Settings
    {
        private static readonly Settings instance = new Settings();

        public CaseSettings CaseSelector { get; private set; }

        static Settings()
        { }

        private Settings()
        {
           CaseSelector = new CaseSettings();
        }

        public static Settings Instance
        {
            get
            {
                return instance;
            }
        }
    }

    public class CaseSettings
    {
        public int CaseSelection = 1;

        public CaseSettings()
        {
            CaseSelection = int.Parse(ConfigurationManager.AppSettings["caseSelector"].ToString());
        }
    }
}

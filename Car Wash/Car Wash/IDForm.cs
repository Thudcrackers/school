using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Windows.Forms;

namespace Car_Wash
{
    public partial class IDForm : Form
    {
        public IDForm()
        {
            InitializeComponent();
        }

        private void submitIDButton_Click(object sender, EventArgs e)
        {
            if (Char.IsLetter(customerIDBox.Text[0]) && Char.IsLetter(customerIDBox.Text[1]) && Char.IsDigit(customerIDBox.Text[2]) &&
                Char.IsDigit(customerIDBox.Text[3]) && Char.IsDigit(customerIDBox.Text[4]) && Char.IsDigit(customerIDBox.Text[5]))
            {
                string path = @"C:/Car Wash/";
                if (!Directory.Exists(path))
                {
                    DirectoryInfo di = Directory.CreateDirectory(path);
                }
                path = @"C:/Car Wash/" + customerIDBox.Text + ".txt";

                if (!File.Exists(path))
                {
                    using (StreamWriter sw = File.CreateText(path))
                        sw.WriteLine("wash");
                    var lineCount = File.ReadLines(path).Count();

                    this.Hide();
                    selectWashForm washForm = new selectWashForm(lineCount);
                    washForm.ShowDialog();
                }
                else
                {
                    int lineCount = File.ReadLines(path).Count();
                    if (lineCount < 5)
                    {
                        using (StreamWriter sw = File.AppendText(path))
                            sw.WriteLine("wash");

                        this.Hide();
                        selectWashForm washForm = new selectWashForm(lineCount);
                        washForm.ShowDialog();
                    }
                    else
                    {
                        FileStream fs = File.Open(path, FileMode.Open);
                        fs.SetLength(0);
                        fs.Close();

                        this.Hide();
                        freeWashForm washForm = new freeWashForm();
                        washForm.ShowDialog();
                    }
                }
                
            }
        }
    }
}

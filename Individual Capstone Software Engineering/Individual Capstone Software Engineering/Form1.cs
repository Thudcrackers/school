using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Individual_Capstone_Software_Engineering
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        public double CAR_WASH_COST = 0;
        Form2 pay = new Form2();

        private void Basic_Click(object sender, EventArgs e)
        {
            CAR_WASH_COST = 5;
            pay.Show();
        }

        private void Ultra_Click(object sender, EventArgs e)
        {
            CAR_WASH_COST = 8;
            pay.Show();
        }

        private void Ultimate_Click(object sender, EventArgs e)
        {
            CAR_WASH_COST = 10;
            pay.Show();
        }

    }
}

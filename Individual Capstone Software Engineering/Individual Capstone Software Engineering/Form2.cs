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
    public partial class Form2 : Form1
    {
        public Form2()
        {
            InitializeComponent();
        }

        string PAYMENT_METHOD = "";

        private void Cash_Click(object sender, EventArgs e)
        {
            PAYMENT_METHOD = "Cash";
        }

        private void Card_Click(object sender, EventArgs e)
        {
            PAYMENT_METHOD = "Card";
            Form3 cardPay = new Form3();
            cardPay.Show();
        }
    }
}

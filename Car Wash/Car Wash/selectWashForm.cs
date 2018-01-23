using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Car_Wash
{
    public partial class selectWashForm : Form
    {
        int washNumber;
        public selectWashForm(int lineCount)
        {
            InitializeComponent();

            washNumber = lineCount;
        }

        private void selectWashButton_Click(object sender, EventArgs e)
        {
            int price = 0;
            if (standardRadio.Checked)
                price = 5;
            else if (extraRadio.Checked)
                price = 8;
            else
                price = 10;
            paymentMethodForm payment = new paymentMethodForm(price, washNumber);
            payment.Show();
            this.Close();
        }
    }
}

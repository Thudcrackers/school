namespace Car_Wash
{
    partial class paymentMethodForm
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
            this.label1 = new System.Windows.Forms.Label();
            this.cashButton = new System.Windows.Forms.Button();
            this.cardButton = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.priceLabel = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.numberOfWashLabel = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(57, 92);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(163, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "Please select a payment method:";
            // 
            // cashButton
            // 
            this.cashButton.Location = new System.Drawing.Point(60, 126);
            this.cashButton.Name = "cashButton";
            this.cashButton.Size = new System.Drawing.Size(75, 23);
            this.cashButton.TabIndex = 1;
            this.cashButton.Text = "Cash";
            this.cashButton.UseVisualStyleBackColor = true;
            this.cashButton.Click += new System.EventHandler(this.cashButton_Click);
            // 
            // cardButton
            // 
            this.cardButton.Location = new System.Drawing.Point(144, 125);
            this.cardButton.Name = "cardButton";
            this.cardButton.Size = new System.Drawing.Size(75, 23);
            this.cardButton.TabIndex = 2;
            this.cardButton.Text = "Card";
            this.cardButton.UseVisualStyleBackColor = true;
            this.cardButton.Click += new System.EventHandler(this.cardButton_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(57, 57);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(65, 13);
            this.label2.TabIndex = 3;
            this.label2.Text = "Your total is:";
            // 
            // priceLabel
            // 
            this.priceLabel.AutoSize = true;
            this.priceLabel.Location = new System.Drawing.Point(129, 57);
            this.priceLabel.Name = "priceLabel";
            this.priceLabel.Size = new System.Drawing.Size(0, 13);
            this.priceLabel.TabIndex = 4;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(60, 24);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(48, 13);
            this.label3.TabIndex = 5;
            this.label3.Text = "Wash #:";
            // 
            // numberOfWashLabel
            // 
            this.numberOfWashLabel.AutoSize = true;
            this.numberOfWashLabel.Location = new System.Drawing.Point(115, 24);
            this.numberOfWashLabel.Name = "numberOfWashLabel";
            this.numberOfWashLabel.Size = new System.Drawing.Size(0, 13);
            this.numberOfWashLabel.TabIndex = 6;
            // 
            // paymentMethodForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 188);
            this.Controls.Add(this.numberOfWashLabel);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.priceLabel);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.cardButton);
            this.Controls.Add(this.cashButton);
            this.Controls.Add(this.label1);
            this.Name = "paymentMethodForm";
            this.Text = "Payment Method";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button cashButton;
        private System.Windows.Forms.Button cardButton;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label priceLabel;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label numberOfWashLabel;
    }
}
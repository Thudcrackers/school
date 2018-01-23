namespace Car_Wash
{
    partial class IDForm
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
            this.customerIDBox = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.submitIDButton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // customerIDBox
            // 
            this.customerIDBox.Location = new System.Drawing.Point(137, 48);
            this.customerIDBox.Name = "customerIDBox";
            this.customerIDBox.Size = new System.Drawing.Size(100, 20);
            this.customerIDBox.TabIndex = 0;
            this.customerIDBox.Text = " ";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(36, 51);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(95, 13);
            this.label1.TabIndex = 1;
            this.label1.Text = "Enter customer ID:";
            // 
            // submitIDButton
            // 
            this.submitIDButton.Location = new System.Drawing.Point(95, 87);
            this.submitIDButton.Name = "submitIDButton";
            this.submitIDButton.Size = new System.Drawing.Size(75, 23);
            this.submitIDButton.TabIndex = 2;
            this.submitIDButton.Text = "Submit";
            this.submitIDButton.UseVisualStyleBackColor = true;
            this.submitIDButton.Click += new System.EventHandler(this.submitIDButton_Click);
            // 
            // IDForm
            // 
            this.AcceptButton = this.submitIDButton;
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 151);
            this.Controls.Add(this.submitIDButton);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.customerIDBox);
            this.Name = "IDForm";
            this.Text = "Enter Customer ID";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox customerIDBox;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button submitIDButton;
    }
}


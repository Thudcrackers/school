namespace Car_Wash
{
    partial class freeWashForm
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
            this.label2 = new System.Windows.Forms.Label();
            this.freeWashButton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(96, 39);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(81, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "Congratulatons!";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(51, 74);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(173, 13);
            this.label2.TabIndex = 1;
            this.label2.Text = "You are eligible for a free car wash!";
            // 
            // freeWashButton
            // 
            this.freeWashButton.Location = new System.Drawing.Point(99, 109);
            this.freeWashButton.Name = "freeWashButton";
            this.freeWashButton.Size = new System.Drawing.Size(75, 23);
            this.freeWashButton.TabIndex = 2;
            this.freeWashButton.Text = "OK";
            this.freeWashButton.UseVisualStyleBackColor = true;
            this.freeWashButton.Click += new System.EventHandler(this.freeWashButton_Click);
            // 
            // freeWashForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 165);
            this.Controls.Add(this.freeWashButton);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Name = "freeWashForm";
            this.Text = "Free Cash Wash!";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button freeWashButton;
    }
}
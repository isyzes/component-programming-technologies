<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form1
    Inherits System.Windows.Forms.Form

    'Форма переопределяет dispose для очистки списка компонентов.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Является обязательной для конструктора форм Windows Forms
    Private components As System.ComponentModel.IContainer

    'Примечание: следующая процедура является обязательной для конструктора форм Windows Forms
    'Для ее изменения используйте конструктор форм Windows Form.  
    'Не изменяйте ее в редакторе исходного кода.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.txtOp1 = New System.Windows.Forms.TextBox()
        Me.txtOp2 = New System.Windows.Forms.TextBox()
        Me.txtResult = New System.Windows.Forms.TextBox()
        Me.Label1 = New System.Windows.Forms.Label()
        Me.Label2 = New System.Windows.Forms.Label()
        Me.Label3 = New System.Windows.Forms.Label()
        Me.Bt_Late = New System.Windows.Forms.Button()
        Me.Bt_ID = New System.Windows.Forms.Button()
        Me.Bt_vtbl = New System.Windows.Forms.Button()
        Me.txtTime1 = New System.Windows.Forms.TextBox()
        Me.txtTime2 = New System.Windows.Forms.TextBox()
        Me.txtTime3 = New System.Windows.Forms.TextBox()
        Me.Label4 = New System.Windows.Forms.Label()
        Me.Label5 = New System.Windows.Forms.Label()
        Me.Label6 = New System.Windows.Forms.Label()
        Me.SuspendLayout()
        '
        'txtOp1
        '
        Me.txtOp1.Location = New System.Drawing.Point(34, 69)
        Me.txtOp1.Name = "txtOp1"
        Me.txtOp1.Size = New System.Drawing.Size(202, 22)
        Me.txtOp1.TabIndex = 0
        Me.txtOp1.Text = "10"
        '
        'txtOp2
        '
        Me.txtOp2.Location = New System.Drawing.Point(281, 69)
        Me.txtOp2.Name = "txtOp2"
        Me.txtOp2.Size = New System.Drawing.Size(202, 22)
        Me.txtOp2.TabIndex = 1
        Me.txtOp2.Text = "20"
        '
        'txtResult
        '
        Me.txtResult.Location = New System.Drawing.Point(549, 69)
        Me.txtResult.Name = "txtResult"
        Me.txtResult.Size = New System.Drawing.Size(202, 22)
        Me.txtResult.TabIndex = 2
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Location = New System.Drawing.Point(34, 50)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(33, 16)
        Me.Label1.TabIndex = 3
        Me.Label1.Text = "op 1"
        '
        'Label2
        '
        Me.Label2.AutoSize = True
        Me.Label2.Location = New System.Drawing.Point(278, 50)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(33, 16)
        Me.Label2.TabIndex = 4
        Me.Label2.Text = "op 2"
        '
        'Label3
        '
        Me.Label3.AutoSize = True
        Me.Label3.Location = New System.Drawing.Point(546, 50)
        Me.Label3.Name = "Label3"
        Me.Label3.Size = New System.Drawing.Size(45, 16)
        Me.Label3.TabIndex = 5
        Me.Label3.Text = "Result"
        '
        'Bt_Late
        '
        Me.Bt_Late.Location = New System.Drawing.Point(34, 203)
        Me.Bt_Late.Name = "Bt_Late"
        Me.Bt_Late.Size = New System.Drawing.Size(202, 23)
        Me.Bt_Late.TabIndex = 6
        Me.Bt_Late.Text = "Late binding"
        Me.Bt_Late.UseVisualStyleBackColor = True
        '
        'Bt_ID
        '
        Me.Bt_ID.Location = New System.Drawing.Point(281, 203)
        Me.Bt_ID.Name = "Bt_ID"
        Me.Bt_ID.Size = New System.Drawing.Size(202, 23)
        Me.Bt_ID.TabIndex = 7
        Me.Bt_ID.Text = "ID_binding"
        Me.Bt_ID.UseVisualStyleBackColor = True
        '
        'Bt_vtbl
        '
        Me.Bt_vtbl.Location = New System.Drawing.Point(549, 203)
        Me.Bt_vtbl.Name = "Bt_vtbl"
        Me.Bt_vtbl.Size = New System.Drawing.Size(202, 23)
        Me.Bt_vtbl.TabIndex = 8
        Me.Bt_vtbl.Text = "Vtbl_binding"
        Me.Bt_vtbl.UseVisualStyleBackColor = True
        '
        'txtTime1
        '
        Me.txtTime1.Location = New System.Drawing.Point(34, 151)
        Me.txtTime1.Name = "txtTime1"
        Me.txtTime1.Size = New System.Drawing.Size(202, 22)
        Me.txtTime1.TabIndex = 9
        '
        'txtTime2
        '
        Me.txtTime2.Location = New System.Drawing.Point(281, 151)
        Me.txtTime2.Name = "txtTime2"
        Me.txtTime2.Size = New System.Drawing.Size(202, 22)
        Me.txtTime2.TabIndex = 10
        '
        'txtTime3
        '
        Me.txtTime3.Location = New System.Drawing.Point(549, 151)
        Me.txtTime3.Name = "txtTime3"
        Me.txtTime3.Size = New System.Drawing.Size(202, 22)
        Me.txtTime3.TabIndex = 11
        '
        'Label4
        '
        Me.Label4.AutoSize = True
        Me.Label4.Location = New System.Drawing.Point(34, 132)
        Me.Label4.Name = "Label4"
        Me.Label4.Size = New System.Drawing.Size(48, 16)
        Me.Label4.TabIndex = 12
        Me.Label4.Text = "Time 1"
        '
        'Label5
        '
        Me.Label5.AutoSize = True
        Me.Label5.Location = New System.Drawing.Point(278, 132)
        Me.Label5.Name = "Label5"
        Me.Label5.Size = New System.Drawing.Size(48, 16)
        Me.Label5.TabIndex = 13
        Me.Label5.Text = "Time 2"
        '
        'Label6
        '
        Me.Label6.AutoSize = True
        Me.Label6.Location = New System.Drawing.Point(546, 132)
        Me.Label6.Name = "Label6"
        Me.Label6.Size = New System.Drawing.Size(48, 16)
        Me.Label6.TabIndex = 14
        Me.Label6.Text = "Time 3"
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(8.0!, 16.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(800, 450)
        Me.Controls.Add(Me.Label6)
        Me.Controls.Add(Me.Label5)
        Me.Controls.Add(Me.Label4)
        Me.Controls.Add(Me.txtTime3)
        Me.Controls.Add(Me.txtTime2)
        Me.Controls.Add(Me.txtTime1)
        Me.Controls.Add(Me.Bt_vtbl)
        Me.Controls.Add(Me.Bt_ID)
        Me.Controls.Add(Me.Bt_Late)
        Me.Controls.Add(Me.Label3)
        Me.Controls.Add(Me.Label2)
        Me.Controls.Add(Me.Label1)
        Me.Controls.Add(Me.txtResult)
        Me.Controls.Add(Me.txtOp2)
        Me.Controls.Add(Me.txtOp1)
        Me.Name = "Form1"
        Me.Text = "Form1"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Friend WithEvents txtOp1 As TextBox
    Friend WithEvents txtOp2 As TextBox
    Friend WithEvents txtResult As TextBox
    Friend WithEvents Label1 As Label
    Friend WithEvents Label2 As Label
    Friend WithEvents Label3 As Label
    Friend WithEvents Bt_Late As Button
    Friend WithEvents Bt_ID As Button
    Friend WithEvents Bt_vtbl As Button
    Friend WithEvents txtTime1 As TextBox
    Friend WithEvents txtTime2 As TextBox
    Friend WithEvents txtTime3 As TextBox
    Friend WithEvents Label4 As Label
    Friend WithEvents Label5 As Label
    Friend WithEvents Label6 As Label
End Class

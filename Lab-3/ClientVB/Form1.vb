Public Class Form1
    Const ITERATIONS = 500000
    Private Sub Bt_Late_Click(sender As Object, e As EventArgs) Handles Bt_Late.Click
        ' Пример позднего связывания
        Dim obj As Object
        Dim i As Long
        Dim Start As DateTime = DateTime.Now
        ' Создание объекта с указанным ProgId
        obj = CreateObject("Lb3AutoSvr.MyMath.1")
        txtResult.Text = obj.Add(txtOp1.Text, txtOp2.Text)
        For i = 1 To ITERATIONS
            obj.Add(txtOp1.Text, txtOp2.Text)
        Next
        txtTime1.Text = (DateTime.Now - Start).TotalMilliseconds
        obj = Nothing
    End Sub

    Private Sub Bt_vtbl_Click(sender As Object, e As EventArgs) Handles Bt_vtbl.Click
        ' Пример связывания через vtbl(очень раннего связывания)
        Dim i As Long
        Dim obj As New AutoSvrLib.MyMath
        Dim Start As DateTime = DateTime.Now
        txtResult.Text = obj.Add(txtOp1.Text, txtOp2.Text)
        For i = 1 To ITERATIONS
            obj.Add(txtOp1.Text, txtOp2.Text)
        Next
        txtTime3.Text = (DateTime.Now - Start).TotalMilliseconds
    End Sub

    Private Sub Bt_ID_Click(sender As Object, e As EventArgs) Handles Bt_ID.Click
        ' Пример ID-связывания 
        Dim obj As AutoSvrLib.MyMath
        ' указание на TypeLib
        Dim i As Long
        Dim Start As DateTime = DateTime.Now
        obj = New AutoSvrLib.MyMath
        txtResult.Text = obj.Add(txtOp1.Text, txtOp2.Text)
        For i = 1 To ITERATIONS
            obj.Add(txtOp1.Text, txtOp2.Text)
        Next
        txtTime2.Text = (DateTime.Now - Start).TotalMilliseconds
    End Sub
End Class

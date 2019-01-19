import turtle
turtle.screensize()

turtle.pensize()
turtle.pencolor("black")
turtle.speed(5)

#矩形
for i in range(2):
    turtle.forward(100)
    turtle.right(90)
    turtle.forward(70)
    turtle.right(90)

turtle.penup()#移动时提起画笔，不绘图
turtle.goto(100,100)#将画笔移动到(100,100)的位置，避免两图部分重叠
turtle.pendown()#移动结束，开始绘画

#正方形
for j in range(4):
    turtle.forward(85)
    turtle.right(90)

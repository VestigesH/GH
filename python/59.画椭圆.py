import turtle
turtle.screensize()


turtle.pensize()
turtle.pencolor("black")
turtle.setheading(90)
primespeed= 1
for k in range(2):                # 将相同的动作重复做一遍
    for j in range(60):
        if j < 30:
            primespeed += 0.2     #加快画笔速度
        else:
            primespeed -= 0.2     #减慢画笔速度
        turtle.forward(primespeed)
        turtle.left(3)            #向左旋转3度



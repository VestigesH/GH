I=eval(input("please input I:"))
reward=float()
if I <=10:
    reward=0.1*I
elif 10<I <=20:
    reward=0.1*10+(I-10)*0.075
elif 20<I <=40:
    reward=0.1*10+0.075*10+(I-20)*0.05
elif 40< I <= 60:
    reward=0.1*10+0.075*10+20*0.05+(I-40)*0.03
elif 60< I <=100:
     reward=0.1*10+0.075*10+20*0.05+20*0.03+(I-60)*0.015
else:
      reward=0.1*10+0.075*10+20*0.05+20*0.03+40*0.015+(100-I)*0.01
print(reward)

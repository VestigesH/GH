#题目：两个乒乓球队进行比赛，各出三人。甲队为a,b,c三人，乙队为x,y,z三人。有人向队员打听比赛的名单。a说他不和x比，c说他不和x,z比，请编程序找出三队赛手的名单。
import itertools
for i in itertools.permutations("xyz"):
    if i[0] != "x" and i[2] != "x" and i[2] != "z":
        print("a vs" ,i[0], "\n","b vs",i[1],"\n", "c vs",i[2])


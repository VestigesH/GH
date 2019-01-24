#题目：英文文档词频以英文原著爱丽丝梦游仙境为例，统计每个词在整部小说中出现的频率，并按词频从大到小进行排序。由于整本书所包含单词较多，为了便于展示，只输出词频大于10的单词。
x=open("D:\\text\\爱丽丝梦游仙境.txt","r",buffering=0)
words=list(x)
for i in words:
    if word.count(i) >10:
        words.sort()
        print(words.reverse())

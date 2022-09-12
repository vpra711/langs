list = list(range(1,6))
list1 = [x for x in list if x%2!=0]
print(list)
print(list1)
print([x*21 for x in list1])
import math 
n = int(input())

i = int(1)
sum = int(0)
mod = int(1e9+7)
#print(mod)
stop_val = int(-1)
while i*i<=n:
    sum = (sum%mod + ((i)*int(n/i))%mod)%mod;
    stop_val = i
    i+=1

l = int(stop_val + 1)
while(l<=n):
    r = int(n/int(n/l))
    num_elements_sum = r-l
    n1 = num_elements_sum

    if num_elements_sum%2==0:
        b = int(n1/2)*(n1+1)
    else:
        b = int((n1+1)/2)*n1
    sum += int(((num_elements_sum+1)*l + b))*(int(n/l))
    l = r+1
print(sum%mod)#<<endl



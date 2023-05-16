package main

import "fmt"

func main(){
	num :=[]int{2,3,4}
	sum:=0
	for i,num:=range num{
		sum+=num
		if num ==2{
			fmt.Println("index: ",i,"num:",num)
		}
	}
	fmt.Println(sum)

	m:=map[string]string{"a":"A","b":"B"}
	for k,v:=range m{
		fmt.Println(k,v)
	}
	for k:=range m {
		fmt.Println("key",k)
	}
}
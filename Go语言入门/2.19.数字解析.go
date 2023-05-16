package main

import(
	"fmt"
	"strconv"
)

func main(){
	f,_:=strconv.ParseFloat("1.23232",64)
	fmt.Printf("%.2f",f)

	n,_:=strconv.ParseInt("111",10,64)
	fmt.Println(n)

	n,_ =strconv.ParseInt("0x100",0,64)

	n1,_:=strconv.Atoi("123")
	fmt.Println(n1)

	n2,err:=strconv.Atoi("AAA")
	fmt.Println(n2,err)
}
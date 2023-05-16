package main

import(
   "fmt"
   "time"
)

func main(){
	t:=time.Now()
	switch{
	case t.Hour()<12:
		fmt.Println("before")
	default:
		fmt.Println("after")
	}
	var s string="hello"
	switch s{ 
	case "hello":fmt.Println("yes")
	default:fmt.Println("no")
	}
	a:=2
	switch a{
	case 1,3:fmt.Println("666")
	default:fmt.Println(a)
	}
}
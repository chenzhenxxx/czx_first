package main

import "fmt"

func main(){
	s:=make([]string,3)
	s[0]="a"
	s[1]="b"
	s=append(s,"c","d","e","f")
	fmt.Println(s)

	c := make([]string,len(s))
	copy(c,s)
	fmt.Println(c)
    
	fmt.Println(s[2:5])
	fmt.Println(s[:4])
	fmt.Println(s[1:])
}
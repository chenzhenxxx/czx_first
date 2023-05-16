package main

import "fmt"

type point struct {
	x,y int
}

func main(){
	s :="hello"
	p :=point{1,2}
	q :=[]int{1,2,3}
	fmt.Println(p)
	fmt.Println(q)

	fmt.Printf("s=%v\n",s)
	fmt.Printf("p=%v\n",p)
	fmt.Printf("p=%+v\n",p)
	fmt.Printf("p=%#v\n",p)

	fmt.Printf("q=%v\n",q)
	fmt.Printf("q=%+v\n",q)
	fmt.Printf("q=%#v\n",q)

	f :=3.133333333
	fmt.Println(f)
	fmt.Printf("%.2f",f)
}
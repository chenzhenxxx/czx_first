package main

import(
	"fmt"
	"time"
)

func main(){
	now:= time.Now()
	fmt.Println(now)
	t:=time.Date(2023,5,16,22,26,0,0,time.UTC)
	fmt.Println(t)
	

	t1,err:=time.Parse("2006-01-02 15:04:05", "2023-5-23 22:27:01")
	if err!=nil{
		panic(err)
	}
	fmt.Println(t1)
	fmt.Println(now.Unix())
}
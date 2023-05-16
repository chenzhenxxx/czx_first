package main

import "fmt"

type user struct{
	name string
	password string
}

func main(){
	a:=user{name:"czx",password:"123"}
	a.password="456"
	fmt.Println(checkPassword(a,"123"))
	fmt.Println(checkPassword2(&a,"456"))
}

func checkPassword(u user, password string )bool{
	return u.password==password
}

func checkPassword2(u *user,password string)bool{
	return u.password==password
}
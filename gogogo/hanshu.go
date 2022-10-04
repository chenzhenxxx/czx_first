package main
import "fmt"

func swap(a string ,b string ) (string,string){
	return b,a
}

func max(num1 int ,num2 int ) int {
	var result int 
	if (num1>num2){
		result =num1
	} else {
		result =num2
	}
	return result
}
func main(){
	a,b:= swap("mma","jkj")
	fmt.Println(a,b)
	c := max(6,12)
	fmt.Println(c)
}
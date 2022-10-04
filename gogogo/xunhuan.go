package main
import "fmt"
func main(){
	// for true {
	// 	fmt.Println("sb")
	// }
	numbers := [6]int{1,2,3,4}

	for a:=0;a<len(numbers);a++{
		fmt.Println(numbers[a])
	}
}
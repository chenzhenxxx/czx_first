package main
import(
	"fmt"
)

func main(){
	for{
		fmt.Println("loop")
		break
	}
	
	for i:=0;i<9;i++{
		if i%2==0 {
			continue
		}
		fmt.Println(i)
	}
}
package main
 
import (
	"database/sql"
	"fmt"
	_ "github.com/go-sql-driver/mysql"
	"log"
)
 
func main() {
 
	db, err := sql.Open("mysql", "root:123456@tcp(127.0.0.1:3306)/DB_TEST")
	db.Ping()
	defer db.Close()
 
	if err != nil {
		fmt.Println("数据库连接失败！")
		log.Fatalln(err)
	}
 
	_, err2 := db.Exec("CREATE TABLE user(id INT NOT NULL , name VARCHAR(20), PRIMARY KEY(ID));")
	if err2 != nil {
		log.Fatal(err2)
	}
 
	fmt.Print("Successfully Created\n")
}

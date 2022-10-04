package main
import (
	"database/sql"
    "fmt"
	_ "github.com/go-sql-driver/mysql"
)
var db *sql.DB
 

func initDB() (err error) {
	
	dsn := "dump:111@tcp(127.0.0.1:6001)/test"
	
	db, err = sql.Open("mysql", dsn)
	if err != nil {
		return err
	}
	err = db.Ping()
	if err != nil {
		return err
	}
	return nil
}
 
func main() {
	err := initDB()
	if err != nil {
		fmt.Printf("init db failed,err:%v\n", err)
		return
	}
	//db.Exec("insert into tb_emp1(id,name,deptid,salary) values(?,?,?,?)", 3, "asd", 13,1500)   //插入
	//db.Exec("update tb_emp1 set salary=5000 where id = ?", 1)    //修改
	// db.Exec("delete from tb_emp1 where id = ?", "3")     //删除

}
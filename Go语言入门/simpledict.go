package main

import (
	"fmt"
	"log"
	"net/http"
	"bytes"
	"encoding/json"
	"io"
	"os"

)

type DictRequest struct {
	TransType string `json:"trans_type"`
	Source string `json:"source"`
	UserID string `json:"user_id"`
}

type DictResponse struct {
		Rc int `json:"rc"`
		Wiki struct {
		} `json:"wiki"`
		Dictionary struct {
			Prons struct {
				EnUs string `json:"en-us"`
				En string `json:"en"`
			} `json:"prons"`
			Explanations []string `json:"explanations"`
			Synonym []string `json:"synonym"`
			Antonym []string `json:"antonym"`
			WqxExample [][]string `json:"wqx_example"`
			Entry string `json:"entry"`
			Type string `json:"type"`
			Related []interface{} `json:"related"`
			Source string `json:"source"`
		} `json:"dictionary"`
	}


func query(word string ) {
	client := &http.Client{}
	resquest := DictRequest{TransType: "en2zh",Source: word}
	buf ,err :=json.Marshal(resquest)
	if err !=nil{
		log.Fatal(err)
	}
	var data =bytes.NewReader(buf)
	req, err := http.NewRequest("POST", "https://lingocloud.caiyunapp.com/v1/dict", data)
	if err != nil {
		log.Fatal(err)
	}
	req.Header.Set("Accept", "application/json, text/plain, */*")
	req.Header.Set("Accept-Language", "zh-CN,zh;q=0.9")
	req.Header.Set("Connection", "keep-alive")
	req.Header.Set("Content-Type", "application/json;charset=UTF-8")
	req.Header.Set("Cookie", "_gcl_au=1.1.1264034034.1685272974; _gid=GA1.2.1542545228.1685272978; _ga=GA1.2.310300469.1685272973; _gat_gtag_UA_185151443_2=1; _ga_65TZCJSDBD=GS1.1.1685272972.1.1.1685273756.0.0.0; _ga_R9YPR75N68=GS1.1.1685272973.1.1.1685273756.54.0.0")
	req.Header.Set("Origin", "https://fanyi.caiyunapp.com")
	req.Header.Set("Referer", "https://fanyi.caiyunapp.com/")
	req.Header.Set("Sec-Fetch-Dest", "empty")
	req.Header.Set("Sec-Fetch-Mode", "cors")
	req.Header.Set("Sec-Fetch-Site", "same-site")
	req.Header.Set("User-Agent", "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/111.0.0.0 Safari/537.36")
	req.Header.Set("X-Authorization", "token:qgemv4jr1y38jyq6vhvi")
	req.Header.Set("app-name", "xy")
	req.Header.Set("device-id", "d0b8836bc29cbd3ad1c7e5f98cb19836")
	req.Header.Set("os-type", "web")
	req.Header.Set("os-version", "")
	req.Header.Set("sec-ch-ua", `"Google Chrome";v="111", "Not(A:Brand";v="8", "Chromium";v="111"`)
	req.Header.Set("sec-ch-ua-mobile", "?0")
	req.Header.Set("sec-ch-ua-platform", `"Linux"`)
	resp, err := client.Do(req)
	if err != nil {
		log.Fatal(err)
	}
	defer resp.Body.Close()
	bodyText, err := io.ReadAll(resp.Body)
	if err != nil {
		log.Fatal(err)
	}
	if resp.StatusCode != 200{
		log.Fatal("bad StatusCode:", resp.StatusCode, "body", string(bodyText))
	}
    
	var dictResponse DictResponse
	err = json.Unmarshal(bodyText,&dictResponse) 
	if err != nil {
		log.Fatal(err)
	}

	fmt.Println(word,"UK: ",dictResponse.Dictionary.Prons.En,"US:",dictResponse.Dictionary.Prons.EnUs)
	for _,item :=range dictResponse.Dictionary.Explanations{
		fmt.Println(item)
	}
}

func main(){
	if len(os.Args) !=2 {
		fmt.Fprintf(os.Stderr, `usage : simpleDict WORD example: simpleDictr hello
		`)
		os.Exit(1)
	}
	 
	 word := os.Args[1]
	 query(word)
}
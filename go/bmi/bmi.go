/*
 * @Author       : Mr.Wang
 * @Date         : 2021-09-13 19:44:49
 * @FilePath     : /go/bmi/bmi.go
 * @Description  : message
 */
package main

import "fmt"

func main() {

	t := ca()
	fmt.Printf("\n体脂率:%.2f%%\n", t)

	var ct bool
	fmt.Printf("\nenter (0:exit/1:continue):")
	fmt.Scan(&ct)
	if ct {
		t := ca()
		fmt.Printf("\n体脂率:%.2f%%\n", t)
	}
}

func ca() float32 {
	var weight float32
	var hight float32
	var sex bool
	var age float32
	fmt.Printf("enter weight(kg):")
	fmt.Scan(&weight)
	fmt.Printf("\nenter hight(m):")
	fmt.Scan(&hight)
	fmt.Printf("\nenter age:")
	fmt.Scan(&age)
	fmt.Printf("\nenter sex(0:男/1:女):")
	fmt.Scan(&sex)
	var t float32
	if !sex {
		var bmi = weight / (hight * hight)
		t = 1.2*bmi + 0.23*age - 5.4 - 10.8
	} else {
		var bmi = weight / (hight * hight)
		t = 1.2*bmi + 0.23*age - 5.4
	}

	// if !sex {
	// 	if 18 <= age && age <= 39 {

	// 	}
	// }
	return t
}

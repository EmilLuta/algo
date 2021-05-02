package main

import (
	"fmt"
	"os/exec"
)

func main() {
	cmd1 := exec.Command("./a.out")
	stdin1, _ := cmd1.StdinPipe()
	stdout1, _ := cmd1.StdoutPipe()
	cmd2 := exec.Command("./a.out")
	stdin2, _ := cmd2.StdinPipe()
	stdout2, _ := cmd2.StdoutPipe()
	cmd3 := exec.Command("./a.out")
	stdin3, _ := cmd3.StdinPipe()
	stdout3, _ := cmd3.StdoutPipe()
	cmd4 := exec.Command("./a.out")
	stdin4, _ := cmd4.StdinPipe()
	stdout4, _ := cmd4.StdoutPipe()
	cmd5 := exec.Command("./a.out")
	stdin5, _ := cmd5.StdinPipe()
	stdout5, _ := cmd5.StdoutPipe()
	cmd1.Start()
	cmd2.Start()
	cmd3.Start()
	cmd4.Start()
	cmd5.Start()

	stdin1.Write([]byte("9\n0\n"))
	out1 := make([]byte, 1024)
	_, _ = stdout1.Read(out1)
	fmt.Printf("A = %s\n", out1)

	stdin2.Write([]byte(fmt.Sprintf("8\n%s", out1)))
	out2 := make([]byte, 1024)
	_, _ = stdout2.Read(out2)
	fmt.Printf("B = %s\n", out2)

	stdin3.Write([]byte(fmt.Sprintf("7\n%s", out2)))
	out3 := make([]byte, 1024)
	_, _ = stdout3.Read(out3)
	fmt.Printf("C = %s\n", out3)

	stdin4.Write([]byte(fmt.Sprintf("6\n%s", out3)))
	out4 := make([]byte, 1024)
	_, _ = stdout4.Read(out4)
	fmt.Printf("D = %s\n", out4)

	stdin5.Write([]byte(fmt.Sprintf("5\n%s", out4)))
	out5 := make([]byte, 1024)
	_, _ = stdout5.Read(out5)
	fmt.Printf("E = %s\n", out5)

	// for {
	// 	time.Sleep(10000000)
	// 	stdin1.Write([]byte(fmt.Sprintf("%s\n", out5)))
	// 	out1 := make([]byte, 1024)
	// 	_, _ = stdout1.Read(out1)
	// 	fmt.Printf("A = %s\n", out1)

	// 	stdin2.Write([]byte(fmt.Sprintf("%s\n", out1)))
	// 	out2 := make([]byte, 1024)
	// 	_, _ = stdout2.Read(out2)
	// 	fmt.Printf("B = %s\n", out2)

	// 	stdin3.Write([]byte(fmt.Sprintf("%s\n", out2)))
	// 	out3 := make([]byte, 1024)
	// 	_, _ = stdout3.Read(out3)
	// 	fmt.Printf("C = %s\n", out1)

	// 	stdin4.Write([]byte(fmt.Sprintf("%s\n", out3)))
	// 	out4 := make([]byte, 1024)
	// 	_, _ = stdout4.Read(out4)
	// 	fmt.Printf("D = %s\n", out4)

	// 	stdin5.Write([]byte(fmt.Sprintf("%s\n", out4)))
	// 	out5 := make([]byte, 1024)
	// 	_, _ = stdout5.Read(out5)
	// 	fmt.Printf("E = %s\n", out5)
	// }
}

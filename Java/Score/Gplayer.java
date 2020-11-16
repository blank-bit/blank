/*********************************************
 @Author       : Mr.Wang
 @Date         : 2020-11-16 12:49:48
 @FilePath     : /Java/Score/Gplayer.java
 @Description  : message
*********************************************/
package Java.Score;

import java.util.Scanner;

public class Gplayer {
	int z = 0;
	
	Scanner sc = new Scanner(System.in);
	
	public void guess() {
	System.out.println("请输入你猜的数(0-9)：");

	if(sc.hasNext())
		z = sc.nextInt();
	
	System.out.println("You guess the number is" + " " + z);
	}

}

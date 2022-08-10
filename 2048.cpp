#include <iostream> // disgusting solution, i was bad when i wrote and im not sure it even should pass
using namespace std;

int main(){
	for(int i = 0; i < 5; i++){
		bool adj = false;
		int two = 0, four = 0, eight = 0, sixteen = 0, thirtytwo = 0, sixtyfour = 0, onehundred = 0, twohundred = 0, fivehundred = 0, onethousand = 0, twothousand = 0, rowone, rowtwo, rowthree, rowfour, largest, temp, prevone = 1, prevtwo = 1, prevthree = 1, prevfour = 1;
		for(int j = 0; j < 4; j++){
			cin>>rowone>>rowtwo>>rowthree>>rowfour;
			if(adj == false){
				if((rowone == prevone || rowone == rowtwo) && rowone != 0){
					adj = true;
				}
				else if((rowtwo == prevtwo || rowtwo == rowthree) && rowtwo != 0){
					adj = true;
				}
				else if((rowthree == prevthree || rowthree == rowfour) && rowthree != 0){
					adj = true;
				}
				else if((rowfour == prevfour && rowone) && rowfour != 0){
					adj = true;
				}


				if((prevone && rowtwo == 0) && rowone != 0){
					adj = true;
				}
				else if((prevtwo && rowone == 0 || prevtwo && rowthree == 0 || rowthree && rowone == 0) && rowtwo != 0){
					adj = true;
				}
				else if((prevthree && rowtwo == 0 || prevthree && rowfour == 0 || rowfour && rowtwo == 0) && rowthree != 0){
					adj = true;
				}
				else if((prevfour && rowthree == 0) && rowfour != 0){
					adj = true;
				}
				prevone = rowone;
				prevtwo = rowtwo;
				prevthree = rowthree;
				prevfour = rowfour;
			}
			
			for(int z = 0; z < 4; z++)
			{
				if(z == 0){
					temp = rowone;
				}
				else if(z == 1){
					temp = rowtwo;
				}
				else if(z == 2){
					temp = rowthree;
				}
				else if(z == 3){
					temp = rowfour;
				}
					switch(temp){
					case 2 :
					two = two + 1;
					break;
					case 4 :
					four = four + 1;
					break;
					case 8 :
					eight = eight + 1;
					break;
					case 16 :
					sixteen = sixteen + 1;
					break;
					case 32 :
					thirtytwo = thirtytwo + 1;
					break;
					case 64 :
					sixtyfour = sixtyfour + 1;
					break;
					case 128 :
					onehundred = onehundred + 1;
					break;
					case 256 :
					twohundred = twohundred + 1;
					break;
					case 512 :
					fivehundred = fivehundred + 1;
					break;
					case 1024 :
					onethousand = onethousand + 1;
					break;
					case 2048 :
					twothousand = twothousand + 1;
					break;
				}
				
				
			}
			
		}
		largest = 0;
		if(two%2 != 0){
			if(two >= 2 && adj == true){
				two = two - 1;
				four = four + (two / 2);
			}
			else if(two == 1 || (adj == false && two > 0)){
				largest = 2;
			}
		}
		else{
			if(two >= 2 && adj == true){
				four = four + (two / 2);
			}
			else if(two == 1 || (adj == false && two > 0)){
				largest = 2;
			}
		}
		if(four%2 != 0){

			if(four >= 2 && adj == true){
				four = four - 1;
				eight = eight + (four / 2);
			}
			else if(four == 1 || (adj == false && four > 0)){
				largest = 4;
			}
		}
		else{
			if(four >= 2 && adj == true){
				eight = eight + (four / 2);
			}
			else if(four == 1 || (adj == false && four > 0)){
				largest = 4;
			}
		}
		if(eight%2 != 0){
			if(eight >= 2 && adj == true){
				eight = eight - 1;
				sixteen = sixteen + (eight / 2);
			}
			else if(eight == 1 || (adj == false && eight > 0)){
				largest = 8;
			}
		}
		else{
			if(eight >= 2 && adj == true){
				sixteen = sixteen + (eight / 2);
			}
			else if(eight == 1 || (adj == false && eight > 0)){
				largest = 8;
			}
		}
		if(sixteen%2 != 0){
			if(sixteen >= 2 && adj == true){
				sixteen = sixteen - 1;
				thirtytwo = thirtytwo + (sixteen / 2);
			}
			else if(sixteen == 1 || (adj == false && sixteen > 0)){
				largest = 16;
			}
		}
		else{
			if(sixteen >= 2 && adj == true){
				thirtytwo = thirtytwo + (sixteen / 2);
			}
			else if(sixteen == 1 || (adj == false && sixteen > 0)){
				largest = 16;
			}
		}
		if(thirtytwo%2 != 0){
			if(thirtytwo >= 2 && adj == true){
				thirtytwo = thirtytwo - 1;
				sixtyfour = sixtyfour + (thirtytwo / 2);
			}
			else if(thirtytwo == 1 || (adj == false && thirtytwo > 0)){
				largest = 32;
			}
		}
		else{
			if(thirtytwo >= 2 && adj == true){
				sixtyfour = sixtyfour + (thirtytwo / 2);
			}
			else if(thirtytwo == 1 || (adj == false && thirtytwo > 0)){
				largest = 32;
			}
		}
		if(sixtyfour%2 != 0){
			if(sixtyfour >= 2 && adj == true){
				sixtyfour = sixtyfour - 1;
				onehundred = onehundred + (sixtyfour / 2);
			}
			else if(sixtyfour == 1 || (adj == false && sixtyfour > 0)){
				largest = 64;
			}
		}
		else{
			if(sixtyfour >= 2 && adj == true){
				onehundred = onehundred + (sixtyfour / 2);
			}
			else if(sixtyfour == 1 || (adj == false && sixtyfour > 0)){
				largest = 64;
			}
		}
		if(onehundred%2 != 0)
		{
			if(onehundred >= 2 && adj == true){
				onehundred = onehundred - 1;
				twohundred = twohundred + (onehundred / 2);
			}
			else if(onehundred == 1 || (adj == false && onehundred > 0)){
				largest = 128;
			}
		}
		else
		{
			if(onehundred >= 2 && adj == true){
				twohundred = twohundred + (onehundred / 2);
			}
			else if(onehundred == 1 || (adj == false && onehundred > 0)){
				largest = 128;
			}
		}
		if(twohundred%2 != 0)
		{
			if(twohundred >= 2 && adj == true){
				twohundred = twohundred - 1;
				fivehundred = fivehundred + (twohundred / 2);
			}
			else if(twohundred == 1|| (adj == false && twohundred > 0)){
				largest = 256;
			}
		}
		else
		{
			if(twohundred >= 2 && adj == true){
				fivehundred = fivehundred + (twohundred / 2);
			}
			else if(twohundred == 1 || (adj == false && twohundred > 0)){
				largest = 256;
			}
		}
		if(fivehundred%2 != 0)
		{
			if(fivehundred >= 2 && adj == true){
				fivehundred = fivehundred - 1;
				onethousand = onethousand + (fivehundred / 2);
			}
			else if(fivehundred == 1 || (adj == false && fivehundred > 0)){
				largest = 512;
			}
		}
		else
		{
			if(fivehundred >= 2 && adj == true){
				onethousand = onethousand + (fivehundred / 2);
			}
			else if(fivehundred == 1 || (adj == false && fivehundred > 0)){
				largest = 512;
			}
		}
		if(onethousand%2 != 0){
			if(onethousand >= 2 && adj == true){
				onethousand = onethousand - 1;
				twothousand = twothousand + (onethousand / 2);
			}
			else if(onethousand == 1 || (adj == false && onethousand > 0)){
				largest = 1024;
			}
		}
		else{
			if(onethousand >= 2 && adj == true){
				twothousand = twothousand + (onethousand / 2);
			}
			else if(onethousand == 1 || (adj == false && onethousand > 0)){
				largest = 1024;
			}
		}
		if(twothousand > 0){
			largest = 2048;
		}
		cout<<largest<<endl;
	}
}
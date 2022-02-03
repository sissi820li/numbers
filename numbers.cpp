#include <iostream> 
#include <string>
using namespace std; 

//list stores the digits of entered number, for example the ones place would store 1 if the number is 20001 
int digits[5] = {0, 0, 0, 0, 0};

//function that converts the number in the ones digit to string 
string digits_ones(int digit){
    if(digit == 1){return "one";}
    if(digit == 2){return "two";}
    if(digit == 3){return "three";}
    if(digit == 4){return "four";}
    if(digit == 5){return "five";}
    if(digit == 6){return "six";}
    if(digit == 7){return "seven";}
    if(digit == 8){return "eight";}
    if(digit == 9){return "nine";}
    return ""; 
}

//function that converts numbers in range 10 - 19 to string 
string digits_teens(int digit){
    if(digit == 1){return "eleven ";}
    if(digit == 2){return "twelve ";}
    if(digit == 3){return "thirteen ";}
    if(digit == 4){return "fourteen ";}
    if(digit == 5){return "fifteen ";}
    if(digit == 6){return "sixteen ";}
    if(digit == 7){return "seventeen ";}
    if(digit == 8){return "eighteen ";}
    if(digit == 9){return "nineteen ";}
    return "ten ";
}

//function that converts the number in the tens digit to string 
string digits_tens(int digit){
    //if number in range 10-19, return appropriate string instead of "ten"
    if(digit == 1){return digits_teens(digits[0]);}
    if(digit == 2){return "twenty";}
    if(digit == 3){return "thirty";}
    if(digit == 4){return "fourty";}
    if(digit == 5){return "fifty";}
    if(digit == 6){return "sixty";}
    if(digit == 7){return "seventy";}
    if(digit == 8){return "eighty";}
    if(digit == 9){return "ninety";}
    return ""; 
}

//function that converts the number in the hundreds digit to string 
string digits_hundreds(){
    if (digits[2] == 0){
        return ""; 
    }
    //formats the string properly, ex) 300 is three hundred but 301 is three hundred AND one 
    else if (digits[0] == 0 && digits[1] == 0){
        return digits_ones(digits[2]) + " hundred "; 
    }
    else{
        return digits_ones(digits[2]) + " hundred and ";
    }
}

//function that converts the number in the thousands digit to string 
string digits_thousands(){ 
    if (digits[3] == 0 && digits[4] == 0){
        return "";
    }
    // converts all teens thousands to strings (ex: 11,000 or 14,000)
    else if (digits[4] == 1){
        if (digits[0] == 0 && digits[1] == 0 && digits[2] == 0){
            return digits_teens(digits[3]) + "thousand "; 
        }
        else if (digits[2] != 0){
            return digits_teens(digits[3])+ "thousand, ";
        }
        else{
            return digits_teens(digits[3]) + "thousand and ";
        }
    }
    //converts other thousands to strings (ex: 30,000)
    else{
        string thousand = "";   
        //converts only the numbers in the thousand ten thousand place to a string 
        if (digits[3] != 0 && digits[4] != 0){
            thousand = digits_tens(digits[4]) + "-"  + digits_ones(digits[3]); 
        }
        else{
            thousand = digits_tens(digits[4]) + digits_ones(digits[3]); 
        }

        //uses the thousand string from previous if else statement and formats appropriately; 
        //ex) 31,000 is thirty-one thousand and 30,000 is thirty thousand 
        if (digits[0] == 0 && digits[1] == 0 && digits[2] == 0){
            return thousand + " thousand ";
        }
        else if (digits[2] != 0){
            return thousand + " thousand, ";
        }
        else{
            return thousand + " thousand and "; 
        }
    } 
} 

//function 1: convert integer to strings 
string IntToString(int number){
    // declaring variables 
    int i = 0;
    int remainder; 
    if (number == 0){
        return "zero"; 
    }

    //range 0 - 99,999 (inclusive), print error if out of range 
    if (number > 99999 || number < 0){
        return "error."; 
    }

    //storing the digits of the entered number into digits[] list
    while(i <= 5){
        //solving for the digits of the number 
        remainder = number % 10; 
        //storing digit in list 
        digits[i] = remainder; 
        number = (number - remainder)/10 ;
        i = i + 1; 
    }

    //returns string after converted from number, does not print  
    if(digits[1] != 1){
        if(digits[0] && digits[1] != 0){
            return digits_thousands() + digits_hundreds() + digits_tens(digits[1])+ "-" + digits_ones(digits[0]); 
        }
        else{
            return digits_thousands() + digits_hundreds() + digits_tens(digits[1]) + digits_ones(digits[0]);
        }
    }
    else{
        return digits_thousands() + digits_hundreds() + digits_tens(digits[1]);
    }
}

//function 2: prints strings in a given sequence 
void PrintIntStrings(int start, int end, int interval){
    // if start is greater than end, print in descending order 
    if(start > end){
        while (end <= start){
            //takes returned value from IntToString function and prints it, each on a seperate line 
            cout << "\n"; 
            cout << IntToString(start);  
            start = start - interval; 
        }
    }
    // if end is greater than start, print in ascending order
    else {
        while (start <= end){
            //takes returned value from IntToString function and prints it, each on a seperate line 
            cout << "\n";
            cout << IntToString(start); 
            start = start + interval; 
        }
    }
}

int main(){   
    //declares variables
    int user_range = 0;
    int second_user_range = 0;
    int start_range = 0; 
    int end_range = 0; 

    //asks user for first range between 1 and 99999, if out of range asks for new number 
    while (user_range < 1 || user_range > 99999){
        cout << "Enter a number between 1 and 99999: " ; 
        cin >> user_range;
    }
    
    //asks user for second range between 1 and 999, if out of range asks for new number 
    while (second_user_range < 1 || second_user_range > 99999){
        cout << "\nEnter a second number between 1 and 99999: " ; 
        cin >> second_user_range;
        if (second_user_range == user_range)
        {
           second_user_range = 0; 
        }
    }
    
    //compares both numbers from user makes the smaller number the start range
    if (user_range < second_user_range){
        start_range = user_range;
        end_range = second_user_range; 
    }
    else{
        start_range = second_user_range;
        end_range = user_range; 
    }

    PrintIntStrings(start_range, end_range, 1);
    return 0;
}
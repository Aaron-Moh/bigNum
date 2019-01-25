#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <iomanip>
#include <stdlib.h>
#include <cmath>
#include <bits/stdc++.h>
#include <tgmath.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

using namespace std;


#define PI 3.14159265

#define error1 "Unfortunately, in this version of Aaron's Calculator, this is not possible :|\n"
#define error2 "Dear Jackass, base of logarithm cannot be 1 :| \n"
#define error3 "Wow! I can't believe that people like you are even alive :/ \n"
#define decimal_error "Unfortunately, in Aaron's Calculator v1.0, decimal operations are not allowed:/ \n"





int to_int(string a);
string to_string(int a);
void reverseStr(string& str);



void mainPage();
void check(int a);
bool isNum(string a);
void Addition();
void Subtraction();
void Multiplication();
void Pheasant_Multiplication();
void LongDivision();
void intDivision();
void Power();
void secondRoot();
void sRoot_P();
void Modulus();
void Fibonacci();
void GCD();
void LCM();
void BinaryConversion();
void BitwiseAND();
void BitwiseOR();
void BitwiseXOR();
void Logarithm_2();
void Logarithm_base();
void isPrime();
void BaseConversion();
void Factorial();
void Sine();
void Cosine();
void Tangent();
void coTangent();
void arcTangent();







class BigInt
{
    string numberString; //This is our number but in string and not in any other kind of data type

    bool isNegative(); //Checks if the given number is negative or not
    bool isPositive(); //Checks if the given number is positive or not
    bool equals(BigInt a); //Checks to see if two given BigNumbers are equal or not
    bool hasDecimals(); //Checks to see if the number has decimals or not
    int decimalPlace(); //Returns the decimal place
    BigInt trimLeadingZeros(); //Erases leading Zeros
    BigInt divideByTwo(); //returns the division of a number by two
    BigInt multiplyByTwo(); //returns the multiplication of a number with two
    BigInt fixDigits(); //adds a '0' if the number is odd

public:

    BigInt(); //Empty Constructor
    BigInt(string number); //String Constructor
    BigInt(long long number); //Long Long type Constructor
    BigInt(int number); //Int type Constructor
    ~BigInt(); //Empty Destructor
    void printing(); //prints the value of numberString


    bool isEven(); //Returns true if given BigInt is Even
    bool isOdd(); //Returns true if given BigInt is Odd
    BigInt setString(string a); //Sets the numberString from the input string a
    string getString(); //Returns the string

    BigInt add(BigInt a); //Adds two given BigInts (Integers)
    BigInt subtract(BigInt a); //Subtracts two BigInt
    BigInt multiply(BigInt a); //Multiplication of two BigInt
    BigInt pheasantMult(BigInt a); //The Russian Pheasant algorithm for multiplication
    BigInt Intdivide(BigInt a); //Returns integer part of BigInt a divided by BigInt B
    BigInt longDivision(BigInt a); //A digit by digit algorithm for multiplication of two numbers
    BigInt power(int a); //Returns BigInt multiplied a times
    BigInt sRoot(); //Returns the second root of the BigInt
    BigInt sRoot_P(int a); //Returns the second root with some precision

    BigInt Negate();//Negates the current value for example -1 is converted to +1 and vice versa
    BigInt absolute();//Absolute of a BigInt

    BigInt modulo(BigInt a);//returns Modulus of a division

    /*

    Extra Features from now on

    */

    bool isNegative_bit();//Return true if the value of given Binary is negative
    BigInt preOperation();//returns Absolute of a BigInt
    BigInt postOperation(bool a);//returns the BigInt with respect to it's sign
    BigInt binaryConversion();//returns binary of a number
    BigInt unBin();//Converts from Binary to Ordinary
    bool bitwiseAndwithOne();//returns true if the given number ends with 1 in it's binary representation
    BigInt and_bit(BigInt a);//Gets the & of two BigInts
    BigInt or_bit(BigInt a);//Returns bitwise or of two BigInts
    BigInt xor_bit(BigInt a);//Returns XOR of two BigInts

    BigInt baseConversion(BigInt a);//Changes the base of 'this' from ten to BigInt a;

    BigInt logarithm_2();//Integer part of a logarithm base 2
    BigInt logarithm_base(BigInt a);//Integer part of a logarithm in the given base

    BigInt factorial();//Returns factorial of a number
    BigInt fibo(int fib);//Gives us the fibonacci sequence

    BigInt GCD(BigInt a);//Returns the GCD of two BigInts
    BigInt LCM(BigInt a);//Returns LCM of two BigInts

    bool isPrime();//Checks if the given BigInt is prime or not

    double Big_sine();
    double Big_cosine();
    double Big_tan();
    double Big_cot();
    double Big_arcTan();

    BigInt randomBigInt();//Generates a random BigInt

    BigInt operator+(BigInt a);
    BigInt operator-(BigInt a);
    BigInt operator*(BigInt a);
    BigInt operator/(BigInt a);
    BigInt operator^(int a);
    BigInt operator%(BigInt a);
    BigInt operator&(BigInt a);//Returns bitwise And of two BigInts
    BigInt operator|(BigInt a);//Returns bitwise Or of two BigInts

    bool operator==(BigInt a);
    bool operator!=(BigInt a);
    bool operator>(BigInt b);
    bool operator<(BigInt b);
    bool operator>=(BigInt a);
    bool operator<=(BigInt a);
    BigInt operator=(BigInt a);

    BigInt& operator++();
    BigInt& operator--();
    BigInt operator++(int);
    BigInt operator--(int);

};

/*

Defining numbers

*/

BigInt null("");
BigInt zero("0");
BigInt one("1");
BigInt two("2");
BigInt ten("10");
BigInt twoPI("360");

/*

Functions implementation

*/

BigInt::BigInt()
{
    numberString="";
}


BigInt::BigInt(string number)
{
    numberString=number;
}


BigInt::BigInt(long long number)
{
    stringstream ss;
    ss >> number;
    numberString=ss.str();
}


BigInt::BigInt(int number)
{
    stringstream ss;
    ss >> number;
    numberString=ss.str();
}


BigInt::~BigInt()
{
}


bool BigInt::isNegative()
{
    return this->numberString[0]=='-';
}


bool BigInt::isPositive()
{
    return !this->isNegative();
}

bool BigInt::equals(BigInt a)
{
    return (this->numberString==a.numberString);
}




bool BigInt::hasDecimals()
{
    int maxi=this->numberString.size()-1;
    for(int i=0;i<maxi;i++)
    {
        if(this->numberString[i]=='.')
        {
            return true;
        }
    }
    return false;
}

int BigInt::decimalPlace()
{
    int maxi=this->numberString.size()-1;

    for(int i=0;i<maxi;i++)
        if(this->numberString[i]=='.')
            return i;
}


BigInt BigInt::trimLeadingZeros()
{
    BigInt temp=*this;
    //if(temp.numberString.find_first_not_of('0')!=string::npos)
    //      temp.setString(temp.numberString.erase(0,temp.numberString.find_first_not_of('0')));
    while(temp.numberString[0]=='0') temp.numberString.erase(0,1);
    return temp;

}


BigInt BigInt::divideByTwo()
{
    return this->longDivision(two);
}


BigInt BigInt::multiplyByTwo()
{
    return this->multiply(two);
}



BigInt BigInt::fixDigits()
{
    BigInt _this=*this;

    if(_this.numberString.size()%2)

        _this.numberString=_this.numberString.insert(0,"0");

    return _this;
}



void BigInt::printing()
{
    if(numberString=="-0") cout << "0";

    else    if(numberString.size()<80)
                for(int i=0;i<numberString.size();i++)
                    {
                        cout << numberString.at(i);
                        Sleep(20);
                    }
    else
    {
        for(int i=0;i<numberString.size();i++)
                {
                    cout << numberString.at(i);
                    Sleep(5);
                }
    }
}



bool BigInt::isEven()
{
    return (this->numberString[this->numberString.length() - 1] % 2 == 0);
}

bool BigInt::isOdd()
{
    return !this->isEven();
}



BigInt BigInt::setString(string a)
{
    this->numberString=a;
    return *this;
}

string BigInt::getString()
{
    return this->numberString;
}



BigInt BigInt::add(BigInt a)
{
    BigInt num1=(*this>a)?*this:a;
    BigInt num2=(*this>a)?a:*this;

    if (num1.isNegative() || num2.isNegative())
    {
        if (num1.isNegative() && num2.isNegative())
        {
            return num1.Negate().add(num2.Negate()).Negate();
        }

        else if (num1.isNegative() && num2.isPositive())
        {
            return num1.Negate().subtract(num2).Negate();
        }

        else
        {
            return num2.Negate().subtract(num1).Negate();
        }
    }

    string results;
    int carry = 0;
    int diff = int(num1.numberString.size() - num2.numberString.size());

    for (int i = 0; i < diff; ++i)
    {
        num2.numberString.insert(num2.numberString.begin(), '0');
    }

    for (int i = int(num1.numberString.size() - 1); i >= 0; --i) {
        int sum = (num1.numberString[i] - '0') + (num2.numberString[i] - '0') + carry;
        carry = 0;
        if (sum <= 9 || i == 0) {
            results.insert(0, to_string(sum));
        }
        else {
            results.insert(0, to_string(sum % 10));
            carry = 1;
        }
    }

    return BigInt(results);
}



BigInt BigInt::subtract(BigInt a)
{
    BigInt b1 = *this, b2 = a;
    if (b1.isNegative() || b2.isNegative()) {
        if (b1.isNegative() && b2.isNegative()) {
            return b1.Negate().subtract(b2.Negate()).Negate();
        }
        else if (b1.isNegative() && b2.isPositive()) {
            return b1.Negate().add(b2).Negate();
        }
        else {
            return b2.Negate().add(b1);
        }
    }
    string results;

    if (b1 < b2)//when we are sure that the answer is negative
    {
        string t = b2.subtract(b1).Negate().getString();
        for (int i = 1; i < t.length(); ++i)
        {
            if (t[i] != '0') break;
            t.erase(1, 1);
        }
        return BigInt(t);
    }

    //this is the algorithm for finding the positive subtractions
    //but as we have given sorted all the other things, this is the cure

    string num3;
    while(b2.numberString.size()<b1.numberString.size())
        b2.numberString.insert(b2.numberString.begin(),'0');
    int carry=0;

    for(int i=b2.numberString.size()-1;i>=0;i--)
    {
        char temp=b1.numberString[i]-b2.numberString[i]+48+carry;

        if(temp<'0')
        {
            temp+=10;
            carry=-1;
        }
        else carry=0;

        num3.insert(num3.begin(),temp);
    }
    while(num3[0]=='0') num3.erase(num3.begin());

    if(num3.empty()) num3='0';

    return BigInt(num3);

}



BigInt BigInt::multiply(BigInt a)
{
     BigInt b1 = a > *this ? a : *this;
    BigInt b2 = a > *this ? *this : a;
    if (b1.isNegative() || b2.isNegative()) {
        if (b1.isNegative() && b2.isNegative()) {
            return b1.Negate().multiply(b2.Negate());
        }
        else if (b1.isNegative() && !b2.isNegative()) {
            return b1.Negate().multiply(b2).Negate();
        }
        else {
            return b2.Negate().multiply(b1).Negate();
        }
    }
    if (b1 == 0 || b2 == 0) return 0;
    int carry = 0;
    int zeroCounter = 0;
    BigInt b = 0;

    for (unsigned int i = 0; i < b1.numberString.size() - b2.numberString.size(); ++i) {
        b2.numberString.insert(b2.numberString.begin(), '0');
    }
    for (long long int i = (b2.numberString.size() - 1); i >= 0; --i) {
        string rr;
        for (long long int j = int(b1.numberString.size() - 1); j >= 0; --j) {
            int val = ((b2.numberString[i] - '0') * (b1.numberString[j] - '0')) + carry;
            carry = 0;
            if (val > 9 && j != 0)
            {
                carry = val / 10;
                rr.insert(0, to_string(val % 10));
            }
            else
            {
                rr.insert(0, to_string(val));
            }
        }
        if (zeroCounter > 0)
        {
            for (int x = 0; x < zeroCounter; ++x)
            {
                rr.append("0");
            }
        }
        ++zeroCounter;
        b =b + BigInt(rr);
    }
    if (b.numberString.find_first_not_of('0') != string::npos)
    {
        b.setString(b.numberString.erase(0, b.numberString.find_first_not_of('0')));
    }
    else
    {
        b=zero;
    }
    return b;
}



BigInt BigInt::pheasantMult(BigInt a)
{
    BigInt first = *this;
    BigInt second = a;
    BigInt result=zero;


    bool sign = false;

    if(first.isNegative()&&second.isNegative())
    {
        first.Negate();
        second.Negate();
    }
    else if(first.isNegative()&&second.isPositive())
    {
        first.Negate();
        sign=true;
    }
    else if(first.isPositive()&&second.isNegative())
    {
        second.Negate();
        sign=true;
    }

    while(second>zero)
    {

        if(second.bitwiseAndwithOne())
        {
            result=result+first;
        }

        first = first.multiplyByTwo();
        second = second.divideByTwo();

    }

    if(sign) result.Negate();

    return result;
}




BigInt BigInt::Intdivide(BigInt a)
{
    if(a==zero)
    {
        MessageBox(0,"Do you even have a brain? I do doubt it :/", "Division by zero is not defined", true);
        return null;
    }

    BigInt first=*this,second=a;
    bool sign=false;

    if(first.isNegative()&&second.isNegative())
    {
        first.Negate();
        second.Negate();
    }
    else if(first.isNegative()&&second.isPositive())
    {
        first.Negate();
        sign=true;
    }
    else if(first.isPositive()&&second.isNegative())
    {
        second.Negate();
        sign=true;
    }

    BigInt result=zero;

    BigInt _first=first.absolute();//A duplicate to hold the number and it should be unchanged in this process

    BigInt estimate=zero;

    int diff=first.numberString.size()-second.numberString.size();

    while(diff>=1&&(diff-1)!=0)
    {
        estimate=second*(ten^(diff-1));
        first=first-estimate;
        result=result+(ten^(diff-1));
        diff=first.numberString.size()-second.numberString.size();
    }

    while(result*second<=_first)
    {
        ++result;
    }
    result--;
    if(sign) result.Negate();
    return result;
}




BigInt BigInt::longDivision(BigInt a)
{
    if(a==zero)
    {
        MessageBox(0,"Do you even have a brain? I do doubt it :/", "Division by zero is not defined", true);
        return null;
    }

    BigInt first=*this,second=a;
    bool sign=false;

    if(first.isNegative()&&second.isNegative())
    {
        first.Negate();
        second.Negate();
    }
    else if(first.isNegative()&&second.isPositive())
    {
        first.Negate();
        sign=true;
    }
    else if(first.isPositive()&&second.isNegative())
    {
        second.Negate();
        sign=true;
    }

    if(second>first) return zero;


    string firstNum=first.numberString;
    string secondNum=second.numberString;

    string f="",res="";
    int i,k=0;

    if(second>first)    res="0";
    else{
        for(i=0;i<secondNum.size();i++)
            f=f+firstNum[i];
        if(f<secondNum){
            f="";
            for(i=0;i<=secondNum.size();i++)
                f=f+firstNum[i];

        }
        while(i<=firstNum.size())
        {
            if((f.size()==secondNum.size()&&f<secondNum)||f.size()<secondNum.size()){
                k=0;
            }
            while(((f.size()==secondNum.size())&&(secondNum<f||f==secondNum))||f.size()>secondNum.size()){
                BigInt forF;
                forF=BigInt(f)-BigInt(secondNum);
                f=forF.numberString;
                k+=1;
            }
            res=res+char(k+48);
            k=0;

            f=f+firstNum[i];
            i++;


            if(f[0]=='0')   f.erase(0,1);

        }
    }

    BigInt result("0");
    result=BigInt(res);

    if(sign) result.Negate();
    return result;

}



BigInt BigInt::power(int a)
{

    if(a<0)
    {
        MessageBox(0,"Unfortunately Aaron's Calc v1.0 does not support decimal places", "Invalid Input", true);
        return zero;
    }

    if (a == 0) return one;
    if (a == 1) return *this;

    BigInt result=one, base = *this;

    while (a)
    {
        if (a & 1)
        {
            result = result*base;
        }
        a >>= 1;

        base = base * base;
    }


    return result;
}



BigInt BigInt::sRoot()
{
    BigInt a=*this;

    bool sign=false;

    if(a.isNegative())
    {
        sign=true;
        a.Negate();
    }

    a=a.fixDigits();

    BigInt temp2=zero;

    for(int i=2;i<=a.numberString.size();i=i+2)
    {
        BigInt temp1=zero;

        string f=a.numberString;
        f.resize(i);

        temp1.setString(f);

        while(temp2*temp2 <= temp1.trimLeadingZeros())
            temp2++;

        temp2--;
        temp2=temp2*ten;
    }

    if(sign)
    {
        BigInt res=temp2/ten;
        res.numberString.append(" i");
        return res;
    }

    return temp2/ten;
}


BigInt BigInt::sRoot_P(int a)
{
    BigInt temp=*this;
    int tempInt=a*2;
    BigInt powOfTen=ten^tempInt;

    BigInt res=temp*powOfTen;
    res=res.sRoot();

    if(temp<0) res.numberString.insert(res.numberString.end()-a-2,'.');
    else res.numberString.insert(res.numberString.end()-a,'.');

    return res;

}


BigInt BigInt::Negate()
{
    if(this->numberString[0]=='-')
        this->numberString.erase(0,1);
    else this->numberString.insert(this->numberString.begin(),'-');

    return *this;
}



BigInt BigInt::absolute()
{
    if(this->isPositive()) return *this;
    return this->Negate();

}



BigInt BigInt::modulo(BigInt a)
{
    BigInt remainder;
    BigInt first=*this;
    BigInt second=a;
    BigInt divided;

    divided=first/second;
    remainder=first-divided*second;

    if(remainder.isNegative()) remainder=remainder+second;

    return remainder;
}


bool BigInt::isNegative_bit()
{
    return this->numberString.at(0)='1';
}

BigInt BigInt::preOperation()
{
    BigInt temp=*this;
    temp.numberString=temp.numberString.erase(0,2);
    return temp;
}

BigInt BigInt::postOperation(bool a)
{
    BigInt temp=*this;
    if(a) temp.numberString.insert(0,"1 ");
    else temp.numberString.insert(0,"0 ");
    return temp;
}

BigInt BigInt::binaryConversion()
{
    BigInt tobeconverted=*this;
    bool sign=false;

    if(tobeconverted.isNegative())
    {

        MessageBox(0,"Unfortunately, in Aron's Calc v1.0, negative Binary is not supported ", "Negative number", true);
        return null;
    }

    BigInt result;

    while(tobeconverted>zero)
    {
        if(tobeconverted%two==one)
        {
            result.numberString.push_back('1');
        }
        else
        {
            result.numberString.push_back('0');
        }
        tobeconverted=tobeconverted.divideByTwo();
    }

    reverseStr(result.numberString);
    string finalRes = result.getString();

    BigInt helper(finalRes);
    return helper;
}


BigInt BigInt::unBin()
{
    BigInt result=zero;
    BigInt base=one;
    BigInt temp=*this;

    if(temp==null) return zero;

    while(temp!=zero)
    {
        BigInt lastDigit=temp%ten;
        temp=temp/ten;
        result=result+(lastDigit*base);
        base=base.multiplyByTwo();
    }


    return result;
}



bool BigInt::bitwiseAndwithOne()
{
    return this->isOdd();
}


BigInt BigInt::and_bit(BigInt a)
{

    BigInt first=*this>a?*this:a;
    BigInt second=*this>a?a:*this;
    BigInt result;

    if(first<0||second<0)
    {

        MessageBox(0,"Unfortunately, in Aron's Calc v1.0, negative Binary is not supported ", "Negative number", true);
        return null;
    }


    first=first.binaryConversion();

    second=second.binaryConversion();


    while(first.numberString.size()>second.numberString.size()) first.numberString.erase(0,1);

    int length=first.numberString.size();

    for(int i=0;i<length;i++)
    {
        int firstNum=first.numberString.at(i)-48;
        int secondNum=second.numberString.at(i)-48;

        if(firstNum*secondNum>0) result.numberString.push_back('1');
        else result.numberString.push_back('0');
    }

    result=result.trimLeadingZeros().unBin();


    return result;

}



BigInt BigInt::or_bit(BigInt a)
{
    BigInt first=*this>a?*this:a;
    BigInt second=*this>a?a:*this;

    BigInt result;

    first=first.binaryConversion();
    second=second.binaryConversion();

    while(first.numberString.size()>second.numberString.size()) second.numberString.insert(0,"0");

    int length=first.numberString.size();

    for(int i=0;i<length;i++)
    {
        int firstNum=first.numberString.at(i)-48;
        int secondNum=second.numberString.at(i)-48;

        if(firstNum+secondNum>0) result.numberString.push_back('1');
        else result.numberString.push_back('0');
    }

    result=result.unBin();

    return result;
}



BigInt BigInt::xor_bit(BigInt a)
{

    BigInt first=*this>a?*this:a;
    BigInt second=*this>a?a:*this;

    BigInt result;

    first=first.binaryConversion();
    second=second.binaryConversion();

    while(first.numberString.size()>second.numberString.size()) second.numberString.insert(0,"0");

    int length=first.numberString.size();

    for(int i=0;i<length;i++)
    {
        int firstNum=first.numberString.at(i)-48;
        int secondNum=second.numberString.at(i)-48;

        if(firstNum==secondNum) result.numberString.push_back('0');
        else result.numberString.push_back('1');
    }

    result=result.unBin();

    return result;

}







BigInt BigInt::baseConversion(BigInt a)
{
    BigInt first=*this;
    BigInt second=a;
    bool sign=false;

    if(second<zero)
    {
        return null;
    }

    if(first.isNegative())
    {
        first.Negate();
        sign=true;
    }

    BigInt result=null;
    while(first!=zero)
    {
        BigInt temp=first%second;

        string tempString=temp.getString();

        while(tempString.size()<second.numberString.size())
        {
            tempString.insert(0,"0");
        }

        result.numberString.insert(0,tempString);

        first=first/second;

        result.numberString.insert(0," ");
    }

    result.numberString.erase(0,1);

    if(sign)
    {
        result.numberString.insert(0,"1 ");
    }
    else result.numberString.insert(0,"0 ");

    return result;

}




BigInt BigInt::logarithm_2()
{
    BigInt temp=*this;
    int result=0;
    string finalRes;

    bool sign=false;

    if(temp.isNegative())
    {
        sign=true;
        temp=temp.Negate();
    }

    while(temp>zero)
    {
        result++;
        temp=temp.divideByTwo();
    }
    result--;
    finalRes=to_string(result);

    if(sign)
    {
        finalRes+=" + 4.5323601 i";
    }

    return BigInt(finalRes);
}






BigInt BigInt::logarithm_base(BigInt a)
{
    BigInt temp=*this;
    int result=0;
    string finalRes;

    bool sign=false;

    if(temp.isNegative())
    {
        sign=true;
        temp=temp.Negate();
    }

    if(a.isNegative())
    {
        cout << error1;
        return null;
    }

    if(a==one)
    {
        cout << error2;
        return null;
    }

    while(temp>zero)
    {
        result++;
        temp=temp/a;
    }

    result--;
    finalRes=to_string(result);

    if(sign)
    {
        finalRes=finalRes+" + i (pi * log["+a.getString()+"] e)";
    }

    return BigInt(finalRes);
}




BigInt BigInt::factorial()
{
    BigInt temp=*this;
    BigInt res=one;


    BigInt ret = one;
    for(BigInt i = one; i <= temp; ++i) ret = ret * i;

    return ret;

}



BigInt BigInt::fibo(int fib)
{

    BigInt a=zero, b=one, c;
    int i;

    if(fib<0)
    {
        MessageBox(0,"NASA should DEFINITELY consider hiring you with this level of ingenuity : | ", "Invalid Input", true);
        return zero;
    }

    if(fib==0) return a;

    for (i=2; i<=fib;i++)
    {
        c=a+b;
        a=b;
        b=c;
    }
    return b;
}



BigInt BigInt::GCD(BigInt a)
{
    BigInt first=*this;
    BigInt second=a;
    BigInt r;

    if(first==zero||second==zero)
    {
        return zero;
    }


    first=first.absolute();
    second=second.absolute();

    while(second!=zero)
    {
        r=first%second;
        first=second;
        second=r;
    }

    return first;
}



BigInt BigInt::LCM(BigInt a)
{
    BigInt first=this->absolute();
    BigInt second=a.absolute();

    BigInt _GCD=first.GCD(second);

    return (first*second)/_GCD;

}



bool BigInt::isPrime()
{
    BigInt number=*this;

    BigInt square=number.sRoot();

    for(BigInt i=two;i<=square;i++)
    {
        if(number%i==zero)
            return false;
    }
    return true;
}



double BigInt::Big_sine()
{
    BigInt bigD=*this;
    bigD=bigD%twoPI;
    int temp;
    temp=to_int(bigD.numberString);

    if(temp==0||temp==180) return 0;

    return sin(temp*PI/180);
}



double BigInt::Big_cosine()
{
    BigInt bigD=*this;
    bigD=bigD%twoPI;
    int temp;
    temp=to_int(bigD.numberString);

    if(temp==90||temp==270) return 0;

    return cos(temp*PI/180);
}


double BigInt::Big_tan()
{
    BigInt bigD=*this;
    bigD=bigD%twoPI;
    int temp;
    temp=to_int(bigD.numberString);
    if(temp==0||temp==180) return 0;
    //if(temp==0||temp==180) return 0;
    return tan(temp*PI/180);
}


double BigInt::Big_cot()
{
    BigInt bigD=*this;
    bigD=bigD%twoPI;
    int temp;
    temp=to_int(bigD.numberString);
    return 1.0/tan(temp*PI/180);
}


double BigInt::Big_arcTan()
{
    BigInt bigD=*this;
    bigD=bigD%BigInt("2000000");
    int temp;
    temp=to_int(bigD.numberString);
    return atan(temp)*180/PI;
}




BigInt BigInt::operator+(BigInt a)
{
    return this->add(a);
}

BigInt BigInt::operator-(BigInt a)
{
    return this->subtract(a);
}

BigInt BigInt::operator*(BigInt a)
{
    return this->multiply(a);
}

BigInt BigInt::operator/(BigInt a)
{
    return this->longDivision(a);
}

BigInt BigInt::operator^(int a)
{
    return this->power(a);
}

BigInt BigInt::operator%(BigInt a)
{
    return this->modulo(a);
}

BigInt BigInt::operator&(BigInt a)
{
    BigInt temp=*this;
    return temp.and_bit(a);
}

BigInt BigInt::operator|(BigInt a)
{
    BigInt temp=*this;
    return temp.or_bit(a);
}

bool BigInt::operator==(BigInt a)
{
    BigInt temp=*this;
    return temp.equals(a);
}

bool BigInt::operator!=(BigInt a)
{
    return !(a==*this);
}



bool BigInt::operator>(BigInt b)
{
    BigInt a=*this;

    if(a.isNegative()||b.isNegative())
    {
        if(a.isNegative()&&b.isNegative())
        {
            a.numberString.erase(0,1);
            b.numberString.erase(0,1);
            return a<b;
        }
        else return !(a.isNegative()&&b.isPositive());
    }

    a=a.trimLeadingZeros();
    b=b.trimLeadingZeros();
    if(a==b) return false;
    if(a.numberString.size()>b.numberString.size()) return true;
    else if(b.numberString.size()>a.numberString.size()) return false;
    else return (a.numberString>b.numberString);
}


bool BigInt::operator<(BigInt b)
{
    return !(*this==b) && !(*this>b);
}


bool BigInt::operator>=(BigInt a)
{
    return ((*this>a) || (*this==a));
}


bool BigInt::operator<=(BigInt a)
{
    return ((*this<a) || (*this==a));
}


BigInt BigInt::operator=(BigInt a)
{
    this->numberString=a.numberString;
    return *this;
}


BigInt& BigInt::operator++() {
    *this = *this + BigInt("1");
    return *this;
}


BigInt& BigInt::operator--() {
    *this = *this - BigInt("1");
    return *this;
}


BigInt BigInt::operator++(int) {
    BigInt t(this->getString());
    ++(*this);
    return t;
}


BigInt BigInt::operator--(int) {
    BigInt t(this->getString());
    --(*this);
    return t;
}




/*

Defining

*/

void aaronCalc()
{
    string s="\n\n\n\tWelcome to Aaron's Calc v1.0";

    for(int i=0;i<s.size();i++)
    {
        cout << s.at(i);
        Sleep(2);
    }
    Sleep(3000);
    mainPage();
}


void loaderScreen()
{
    char a=177,b=219;
    SetConsoleTitle("Loading");
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, 0x02);

    cout << "\n\n\n\n\n\n\t\t\t\t\t\t\tLoading...\n";
    cout << "\n\t\t\t\t\t";

    for(int i=0;i<40;i++)
    {
        cout << b;
        Sleep(20);
    }
}


void mainPage()
{
    system("CLS");
    SetConsoleTitle("Choosing");
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN);

    cout << "\n\tPlease choose your desired operation ;) ";
    SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_GREEN);

    /*cout << "\n\n\n\t\t1. Addition\t\t\t2 .Subtraction\t\t\t3. Multiplication";

    cout << "\n\n\t\t4. Pheasant Multiplication\t5. SlowDivision\t\t\t6. MainDivision";

    cout << "\n\n\t\t7. Power\t\t\t8. sRoot\t\t\t9. sRoot(precision)";

    cout << "\n\n\t\t10. Modulus\t\t\t11. Fibonacci\t\t\t12. GCD";

    cout << "\n\n\t\t13. LCM\t\t\t\t14. Binary Conversion\t\t15. Bitwise AND";

    cout << "\n\n\t\t16. Bitwise OR\t\t\t17. Bitwise XOR\t\t\t18. Logarithm 2";

    cout << "\n\n\t\t19. Logarithm\t\t\t20. isPrime\t\t\t21. Base Conversion";

    cout << "\n\n\t\t22. Factorial\t\t\t23. Sine\t\t\t24. Cosine";

    cout << "\n\n\t\t25. Tangent\t\t\t26. Cotangent\t\t\t27. Arctangent";

    cout << "\n\n\t\t--------------------------------------------------------------------------------\n\n\t\t\t";
    */

    string s="\n\n\n\t\t1. Addition\t\t\t2. Subtraction\n\t\t3. Multiplication\t\t4. Pheasant Multiplication\n\t\t5. SlowDivision\t\t\t6. MainDivision\n\t\t7. Power\t\t\t8. sRoot\n\t\t9. sRoot(precision)\t\t10. Modulus\n\t\t11. Fibonacci\t\t\t12. GCD\n\t\t13. LCM\t\t\t\t14. Binary Conversion\n\t\t15. Bitwise AND\t\t\t16. Bitwise OR\n\t\t17. Bitwise XOR\t\t\t18. Logarithm 2\n\t\t19. Logarithm\t\t\t20. isPrime\n\t\t21. Base Conversion\t\t22. Factorial\n\t\t23. Sine\t\t\t24. Cosine\n\t\t25. Tangent\t\t\t26. Cotangent\n\t\t27. Arctangent\n\n\t--------------------------------------------------------------------------------\n\n\t\t\t";
    for(int i=0;i<s.size();i++)
    {
        cout << s.at(i);
        Sleep(2);
    }
    int a=0;
    cin >> a;

    check(a);

}



void check(int a)
{
    switch(a)
    {
    case 1:
        system("CLS");
        //cout << "\n\n\n\n\t\t\tU chose addition :) \n";
        loaderScreen();
        Addition();
        break;

    case 2:
        system("CLS");
        //cout << "\n\n\n\n\t\t\tU chose subtraction :) \n";
        loaderScreen();
        Subtraction();
        break;

    case 3:
        system("CLS");
        //cout << "\n\n\n\n\t\t\tU chose multiplication v1.0 :) \n";
        loaderScreen();
        Multiplication();
        break;

    case 4:
        system("CLS");
        //cout << "\n\n\n\n\t\t\tU chose multiplication v2.0 :) \n";
        loaderScreen();
        Pheasant_Multiplication();
        break;

    case 5:
        system("CLS");
        //cout << "\n\n\n\n\t\t\tU chose division v1.0 :) \n";
        loaderScreen();
        intDivision();
        break;

    case 6:
        system("CLS");
        //cout << "\n\n\n\n\t\t\tU chose division v2.0 :) \n";
        loaderScreen();
        LongDivision();
        break;

    case 7:
        system("CLS");
        //cout << "\n\n\n\n\t\t\tU chose power :) \n";
        loaderScreen();
        Power();
        break;

    case 8:
        system("CLS");
        //cout << "\n\n\n\n\t\t\tU chose sRoot :) \n";
        loaderScreen();
        secondRoot();
        break;
    case 9:
        system("CLS");
        //cout << "\n\n\n\n\t\t\tU chose sRoot (with precision) :) \n";
        loaderScreen();
        sRoot_P();
        break;

    case 10:
        system("CLS");
        //cout << "\n\n\n\n\t\t\tU chose Modulus :) \n";
        loaderScreen();
        Modulus();
        break;

    case 11:
        system("CLS");
        //cout << "\n\n\n\n\t\t\tU chose Fibonacci :) \n";
        loaderScreen();
        Fibonacci();
        break;

    case 12:
        system("CLS");
        //cout << "\n\n\n\n\t\t\tU chose GCD :) \n";
        loaderScreen();
        GCD();
        break;

    case 13:
        system("CLS");
        //cout << "\n\n\n\n\t\t\tU chose LCM :) \n";
        loaderScreen();
        LCM();
        break;
    case 14:
        system("CLS");
        //cout << "\n\n\n\n\t\t\tU chose Binary Conversion :) \n";
        loaderScreen();
        BinaryConversion();
        break;

    case 15:
        system("CLS");
        //cout << "\n\n\n\n\t\t\tU chose Bitwise AND :) \n";
        loaderScreen();
        BitwiseAND();
        break;
    case 16:
        system("CLS");
        //cout << "\n\n\n\n\t\t\tU chose Bitwise OR :) \n";
        loaderScreen();
        BitwiseOR();
        break;
    case 17:
        system("CLS");
        //cout << "\n\n\n\n\t\t\tU chose Bitwise XOR :) \n";
        loaderScreen();
        BitwiseXOR();
        break;

    case 18:
        system("CLS");
        //cout << "\n\n\n\n\t\t\tU chose Log2 :) \n";
        loaderScreen();
        Logarithm_2();
        break;

    case 19:
        system("CLS");
        //cout << "\n\n\n\n\t\t\tU chose Logarithm :) \n";
        loaderScreen();
        Logarithm_base();
        break;

    case 20:
        system("CLS");
        //cout << "\n\n\n\n\t\t\tU chose checking for Prime :) \n";
        loaderScreen();
        isPrime();
        break;

    case 21:
        system("CLS");
        //cout << "\n\n\n\n\t\t\tU chose Base Conversion :) \n";
        loaderScreen();
        BaseConversion();
        break;

    case 22:
        system("CLS");
        //cout << "\n\n\n\n\t\t\tU chose Factorial :) \n";
        loaderScreen();
        Factorial();
        break;

    case 23:
        system("CLS");
        //cout << "\n\n\n\n\t\t\tU chose Sine :) \n";
        loaderScreen();
        Sine();
        break;

    case 24:
        system("CLS");
        //cout << "\n\n\n\n\t\t\tU chose Cosine :) \n";
        loaderScreen();
        Cosine();
        break;

    case 25:
        system("CLS");
        //cout << "\n\n\n\n\t\t\tU chose Tangent :) \n";
        loaderScreen();
        Tangent();
        break;

    case 26:
        system("CLS");
        //cout << "\n\n\n\n\t\t\tU chose Cotangent :) \n";
        loaderScreen();
        coTangent();
        break;
    case 27:
        system("CLS");
        //cout << "\n\n\n\n\t\t\tU chose Arctangent :) \n";
        loaderScreen();
        arcTangent();
        break;
    default:

        MessageBox(0,"NASA should DEFINITELY consider hiring you with this ASTONISHING level of ingenuity : | ", "Invalid Input", true);
        mainPage();
        break;
    }

}


BigInt firstInput();
BigInt secondInput();



bool isNum(string a)
{
    string tempString=a;

    if(tempString=="") return false;

    for(int i=0;i<tempString.size();i++)
    {
        char temp=tempString.at(i);
        bool tempBool=(temp<58&&temp>47);
        if(i==0)
        {
            if(tempBool || tempString.at(0)==45)    {}
            else return false;
        }

        else
        {
            if(tempBool)    {}

            else return false;
        }
    }

    return true;
}


BigInt firstInput()
{
    BigInt first;
    string a;

    inputeror:

    cout << '\t';
    cin >> a;
    //getline(cin,a);

    string DONE;

    for(int i=0;i<a.size();i++)
    {
        if(a.at(i)!=' ')
            DONE+=a.at(i);
    }



    if(!isNum(DONE))
    {
        MessageBox(0,"It is hard to believe that people like you are even alive : | ", "Invalid Input", true);
        goto inputeror;
        firstInput();
    }

    if(DONE=="-")
    {
        MessageBox(0,"It is hard to believe that people like you are even alive : | ", "Invalid Input", true);
        goto inputeror;
    }

    first.setString(DONE);
    return first;
}


BigInt secondInput()
{
    BigInt second;
    string a;
    inputeror:
    cout << '\t';
    cin >> a;
    //getline(cin,a);

    string DONE;

    for(int i=0;i<a.size();i++)
    {
        if(a.at(i)!=' ')
            DONE+=a.at(i);
    }

    if(DONE=="-")
    {
        MessageBox(0,"It is hard to believe that people like you are even alive : | ", "Invalid Input", true);
        goto inputeror;
        secondInput();
    }


    if(!isNum(DONE))
    {
        MessageBox(0,"It is hard to believe that people like you are even alive : | ", "Invalid Input", true);
        goto inputeror;
        secondInput();
    }



    second.setString(DONE);
    return second;
}


int precisionInput()
{
    int _precision;
    cout << "\n\n\tNow please enter the desired precision: ";
    cin >> _precision;
    if(_precision<2)
    {
        MessageBox(0,"Even a puppy knows how to initialize this but you : | ", "Invalid Input", true);
        precisionInput();
    }
    if(_precision>50) MessageBox(0,"Unfortunately that is going to take a while", "Runtime", true);
    return _precision;
}


void Addition()
{

    while(1)
    {
        system("CLS");
        SetConsoleTitle("Addition");
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hStdOut, 0x9);


        cout << "\n\n\tThis is the implementation of addition on Big Numbers!";

        cout << "\n\n\tNow please enter two numbers (to exit, enter 0 and 0 as input numbers):\n\n";

        SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN);

        BigInt first=firstInput();
        BigInt second=secondInput();
        BigInt result;

        if(first==zero && second == zero)
            mainPage();

        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_BLUE);
        cout << "\n\tResult of sum is:\n\n";

        result=first+second;

        cout << '\t';

        SetConsoleTextAttribute(hStdOut, 0x02);

        result.printing();
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_GREEN);

        cout << "\n\n\t";
        system("PAUSE");
    }
}


void Subtraction()
{

    while(1)
    {
        system("CLS");
        SetConsoleTitle("Subtraction");
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hStdOut, 0x9);


        cout << "\n\n\tThis is the implementation of subtraction on Big Numbers!";

        cout << "\n\n\tNow please enter two numbers (to exit, enter 0 and 0 as input numbers):\n\n";

        SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN);

        BigInt first=firstInput();
        BigInt second=secondInput();
        BigInt result;

        if(first==zero && second == zero)
            mainPage();

        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_BLUE);
        cout << "\n\tResult of subtraction is:\n\n";

        result=first-second;

        cout << '\t';

        SetConsoleTextAttribute(hStdOut, 0x02);

        result.printing();
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_GREEN);

        cout << "\n\n\t";
        system("PAUSE");
    }
}


void Multiplication()
{
    while(1)
    {
        system("CLS");
        SetConsoleTitle("Multiplication");
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hStdOut, 0x9);


        cout << "\n\n\tThis is the implementation of Multiplication on Big Numbers!";
        SetConsoleTextAttribute(hStdOut, 0x4);
        cout << "\n\t*This method is the main algorithm for multiplication!";
        SetConsoleTextAttribute(hStdOut, 0x9);
        cout << "\n\n\tNow please enter two numbers (to exit, enter 0 and 0 as input numbers):\n\n";

        SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN);

        BigInt first=firstInput();
        BigInt second=secondInput();
        BigInt result;

        if(first==zero && second == zero)
            mainPage();

        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_BLUE);
        cout << "\n\tResult of multiplication is:\n\n";

        result=first.multiply(second);

        cout << '\t';

        SetConsoleTextAttribute(hStdOut, 0x02);

        result.printing();
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_GREEN);

        cout << "\n\n\t";
        system("PAUSE");
    }
}


void Pheasant_Multiplication()
{
    while(1)
    {
        system("CLS");
        SetConsoleTitle("Multiplication");
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hStdOut, 0x9);


        cout << "\n\n\tThis is the implementation of Multiplication on Big Numbers!";
        SetConsoleTextAttribute(hStdOut, 0x4);
        cout << "\n\t*This method is the second algorithm for multiplication\n\t**It is also faster by a fraction!";
        SetConsoleTextAttribute(hStdOut, 0x9);
        cout << "\n\n\tNow please enter two numbers (to exit, enter 0 and 0 as input numbers):\n\n";

        SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN);

        BigInt first=firstInput();
        BigInt second=secondInput();
        BigInt result;

        if(first==zero && second == zero)
            mainPage();

        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_BLUE);
        cout << "\n\tResult of Pheasant Multiplication is:\n\n";

        result=first.pheasantMult(second);

        cout << '\t';

        SetConsoleTextAttribute(hStdOut, 0x02);

        result.printing();
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_GREEN);

        cout << "\n\n\t";
        system("PAUSE");
    }
}


void intDivision()
{
   while(1)
    {
        system("CLS");
        SetConsoleTitle("Division v1.0");
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hStdOut, 0x9);


        cout << "\n\n\tThis is the implementation of Division on Big Numbers!";
        SetConsoleTextAttribute(hStdOut, 0x4);
        cout << "\n\t*This method is the slower algorithm for division (slower by some considerable margin)!";
        SetConsoleTextAttribute(hStdOut, 0x9);
        cout << "\n\n\tNow please enter two numbers (to exit, enter 0 and 0 as input numbers):\n\n";

        SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN);

        BigInt first=firstInput();
        BigInt second=secondInput();
        BigInt result;

        if(first==zero && second == zero)
            mainPage();

        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_BLUE);
        cout << "\n\tResult of division is:\n\n";

        result=first.Intdivide(second);

        cout << '\t';

        SetConsoleTextAttribute(hStdOut, 0x02);

        result.printing();
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_GREEN);

        cout << "\n\n\t";
        system("PAUSE");
    }
}

void LongDivision()
{
    while(1)
    {
        system("CLS");
        SetConsoleTitle("Division");
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hStdOut, 0x9);


        cout << "\n\n\tThis is the implementation of Division on Big Numbers!";
        SetConsoleTextAttribute(hStdOut, 0x4);
        cout << "\n\t*This method is the main algorithm for division!";
        SetConsoleTextAttribute(hStdOut, 0x9);
        cout << "\n\n\tNow please enter two numbers (to exit, enter 0 and 0 as input numbers):\n\n";

        SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN);

        BigInt first=firstInput();
        BigInt second=secondInput();
        BigInt result;

        if(first==zero && second == zero)
            mainPage();

        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_BLUE);
        cout << "\n\tResult of division is:\n\n";

        result=first/second;

        cout << '\t';

        SetConsoleTextAttribute(hStdOut, 0x02);

        result.printing();
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_GREEN);

        cout << "\n\n\t";
        system("PAUSE");
    }
}


void Power()
{

   while(1)
    {
        system("CLS");
        SetConsoleTitle("Power");
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hStdOut, 0x9);


        cout << "\n\n\tThis is the implementation of Power on Big Numbers!";

        SetConsoleTextAttribute(hStdOut, 0x9);
        cout << "\n\n\tNow please enter two numbers (to exit, enter 0 and 0 as input numbers):\n\n";

        SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN);

        BigInt first=firstInput();
        int second;

        cout << '\t';
        cin >> second;

        if(abs(second) > 2000) MessageBox(0,"Unfortunately that is going to take a while", "Runtime", true);

        BigInt result;

        if(first==zero && second == 0)
            mainPage();

        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_BLUE);
        cout << "\n\tResult of power is:\n\n\t";

        result=first^second;

        SetConsoleTextAttribute(hStdOut, 0x02);

        result.printing();
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_GREEN);

        cout << "\n\n\t";
        system("PAUSE");
    }
}

void secondRoot()
{
    while(1)
    {
        system("CLS");
        SetConsoleTitle("Second Root");
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hStdOut, 0x9);


        cout << "\n\n\tThis is the implementation of Integer Square Root on Big Numbers!";

        SetConsoleTextAttribute(hStdOut, 0x9);
        cout << "\n\n\tNow please enter a number (to exit, enter 0 input numbers):\n\n";

        SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN);

        BigInt first=firstInput();


        BigInt result;

        if(first==zero)
            mainPage();

        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_BLUE);
        cout << "\n\tResult of Integer Square Root is:\n\n\t";

        result=first.sRoot();

        SetConsoleTextAttribute(hStdOut, 0x02);

        result.printing();
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_GREEN);

        cout << "\n\n\t";
        system("PAUSE");
    }
}


void sRoot_P()
{
    while(1)
    {
        system("CLS");
        SetConsoleTitle("Second Root - with desired precision");
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hStdOut, 0x9);


        cout << "\n\n\tThis is the implementation of Integer Square Root on Big Numbers!";

        cout << "\n\n\tNow please enter a number (to exit, enter 0 input numbers):\n\n";

        SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN);

        BigInt first=firstInput();

        int _precision;

        SetConsoleTextAttribute(hStdOut, 0x9);
        _precision=precisionInput();

        BigInt result;

        if(first==zero)
            mainPage();

        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_BLUE);
        cout << "\n\tResult of Integer Square Root is:\n\n\t";

        result=first.sRoot_P(_precision);

        SetConsoleTextAttribute(hStdOut, 0x02);

        result.printing();
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_GREEN);

        cout << "\n\n\t";
        system("PAUSE");
    }
}


void Modulus()
{
   while(1)
    {
        system("CLS");
        SetConsoleTitle("Modulus");
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hStdOut, 0x9);


        cout << "\n\n\tThis is the implementation of Modulus on Big Numbers!";
        SetConsoleTextAttribute(hStdOut, 0x9);
        cout << "\n\n\tNow please enter two numbers (to exit, enter 1 and 0 as input numbers):\n\n";

        SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN);

        BigInt first=firstInput();
        BigInt second=secondInput();

        if(first<0 && second<0)
        {
            first.Negate();
            second.Negate();
        }

        BigInt result;

        if(first==one && second == zero)
            mainPage();

        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_BLUE);
        cout << "\n\tModulus is:\n\n";

        result=first%second;

        cout << '\t';

        SetConsoleTextAttribute(hStdOut, 0x02);

        result.printing();
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_GREEN);

        cout << "\n\n\t";
        system("PAUSE");
    }
}


void Fibonacci()
{
    while(1)
    {
        system("CLS");
        SetConsoleTitle("Fibonacci");
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hStdOut, 0x9);


        cout << "\n\n\tThis is the nth term on Fibonacci which is obviously a Big Numbers!";

        SetConsoleTextAttribute(hStdOut, 0x9);
        cout << "\n\n\tNow please enter the desired term of Fibonacci sequence (to exit, enter 0 input numbers):\n\n\t";

        SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN);

        int first;

        cin >> first;

        BigInt result;

        if(first==0)
            mainPage();

        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_BLUE);
        cout << "\n\tThe desired number is:\n\n\t";

        result=result.fibo(first);

        SetConsoleTextAttribute(hStdOut, 0x02);

        result.printing();
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_GREEN);

        cout << "\n\n\t";
        system("PAUSE");
    }
}


void GCD()
{
    while(1)
    {
        system("CLS");
        SetConsoleTitle("GCD");
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hStdOut, 0x9);


        cout << "\n\n\tThis is the implementation of GCD on Big Numbers!";

        cout << "\n\n\tNow please enter two numbers (to exit, enter 0 and 0 as input numbers):\n\n";

        SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN);

        BigInt first=firstInput();
        BigInt second=secondInput();
        BigInt result;

        if(first==zero && second == zero)
            mainPage();

        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_BLUE);
        cout << "\n\tResult of GCD is:\n\n";

        result=first.GCD(second);

        cout << '\t';

        SetConsoleTextAttribute(hStdOut, 0x02);

        result.printing();
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_GREEN);

        cout << "\n\n\t";
        system("PAUSE");
    }
}


void LCM()
{
    while(1)
    {
        system("CLS");
        SetConsoleTitle("LCM");
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hStdOut, 0x9);


        cout << "\n\n\tThis is the implementation of LCM on Big Numbers!";

        cout << "\n\n\tNow please enter two numbers (to exit, enter 0 and 0 as input numbers):\n\n";

        SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN);

        BigInt first=firstInput();
        BigInt second=secondInput();
        BigInt result;

        if(first==zero && second == zero)
            mainPage();

        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_BLUE);

        result=first.LCM(second);
        if(result!=null)
            cout << "\n\tResult of LCM is:\n\n";

        cout << '\t';

        SetConsoleTextAttribute(hStdOut, 0x02);

        result.printing();
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_GREEN);

        cout << "\n\n\t";
        system("PAUSE");
    }
}


void BinaryConversion()
{
   while(1)
    {
        system("CLS");
        SetConsoleTitle("Binary Conversion");
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hStdOut, 0x9);


        cout << "\n\n\tThis is the implementation of Binary Conversion on Big Numbers!";
        SetConsoleTextAttribute(hStdOut, 0x4);
        cout << "\n\t*The first digit is the sign! One for negative and Zero for positive!";
        SetConsoleTextAttribute(hStdOut, 0x9);
        cout << "\n\n\tNow please enter a number (to exit, enter 0 input numbers):\n\n";

        SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN);

        BigInt first=firstInput();


        BigInt result;

        if(first==zero)
            mainPage();

        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_BLUE);
        cout << "\n\tResult of Binary Conversion is:\n\n\t";

        result=first.binaryConversion();

        SetConsoleTextAttribute(hStdOut, 0x02);

        result.printing();
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_GREEN);

        cout << "\n\n\t";
        system("PAUSE");
    }
}


void BitwiseAND()
{
  while(1)
    {
        system("CLS");
        SetConsoleTitle("Binary AND");
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hStdOut, 0x9);


        cout << "\n\n\tThis is the implementation of Binary AND on Big Numbers!";

        cout << "\n\n\tNow please enter two numbers (to exit, enter 0 and 0 as input numbers):\n\n";

        SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN);

        BigInt first=firstInput();


        BigInt second=secondInput();

        if(first==zero && second == zero)
            mainPage();

        if(first<0)
        {
            MessageBox(0,"Unfortunately, in Aaron's Calc v1.0, negative Binary is not supported", "Invalid Input", true);
            first=firstInput();
        }
        if(second<0)
        {
            MessageBox(0,"Unfortunately, in Aaron's Calc v1.0, negative Binary is not supported", "Invalid Input", true);
            second=secondInput();
        }

        BigInt result;


        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_BLUE);
        cout << "\n\tResult of Bitwise AND is:\n\n";

        result=first&second;

        cout << '\t';

        SetConsoleTextAttribute(hStdOut, 0x02);

        result.printing();
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_GREEN);

        cout << "\n\n\t";
        system("PAUSE");
    }
}


void BitwiseOR()
{
    while(1)
    {
        system("CLS");
        SetConsoleTitle("Binary OR");
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hStdOut, 0x9);


        cout << "\n\n\tThis is the implementation of Binary OR on Big Numbers!";

        cout << "\n\n\tNow please enter two numbers (to exit, enter 0 and 0 as input numbers):\n\n";

        SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN);

        BigInt first=firstInput();
        BigInt second=secondInput();

        if(first==zero && second == zero)
            mainPage();

        if(first<0)
        {
            MessageBox(0,"Unfortunately, in Aaron's Calc v1.0, negative Binary is not supported", "Invalid Input", true);
            first=firstInput();
        }
        if(second<0)
        {
            MessageBox(0,"Unfortunately, in Aaron's Calc v1.0, negative Binary is not supported", "Invalid Input", true);
            second=secondInput();
        }

        BigInt result;

        if(first==zero && second == zero)
            mainPage();

        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_BLUE);
        cout << "\n\tResult of Bitwise OR is:\n\n";

        result=first|second;

        cout << '\t';

        SetConsoleTextAttribute(hStdOut, 0x02);

        result.printing();
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_GREEN);

        cout << "\n\n\t";
        system("PAUSE");
    }
}


void BitwiseXOR()
{
    while(1)
    {
        system("CLS");
        SetConsoleTitle("Binary XOR");
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hStdOut, 0x9);


        cout << "\n\n\tThis is the implementation of Binary XOR on Big Numbers!";

        cout << "\n\n\tNow please enter two numbers (to exit, enter 0 and 0 as input numbers):\n\n";

        SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN);

        BigInt first=firstInput();
        BigInt second=secondInput();

        if(first==zero && second == zero)
            mainPage();

        if(first<0)
        {
            MessageBox(0,"Unfortunately, in Aaron's Calc v1.0, negative Binary is not supported", "Invalid Input", true);
            first=firstInput();
        }
        if(second<0)
        {
            MessageBox(0,"Unfortunately, in Aaron's Calc v1.0, negative Binary is not supported", "Invalid Input", true);
            second=secondInput();
        }

        BigInt result;

        if(first==zero && second == zero)
            mainPage();

        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_BLUE);
        cout << "\n\tResult of Bitwise XOR is:\n\n";

        result=first.xor_bit(second);

        cout << '\t';

        SetConsoleTextAttribute(hStdOut, 0x02);

        result.printing();
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_GREEN);

        cout << "\n\n\t";
        system("PAUSE");
    }
}


void Logarithm_2()
{
    while(1)
    {
        system("CLS");
        SetConsoleTitle("Logarithm Base 2");
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hStdOut, 0x9);


        cout << "\n\n\tThis is the implementation of Log2 on Big Numbers!";

        SetConsoleTextAttribute(hStdOut, 0x9);
        cout << "\n\n\tNow please enter a number (to exit, enter 0 input numbers):\n\n";

        SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN);

        BigInt first=firstInput();


        BigInt result;

        if(first==zero)
            mainPage();

        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_BLUE);
        cout << "\n\tResult of Log2 (as an Integer) is:\n\n\t";

        result=first.logarithm_2();

        SetConsoleTextAttribute(hStdOut, 0x02);

        result.printing();
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_GREEN);

        cout << "\n\n\t";
        system("PAUSE");
    }
}


void Logarithm_base()
{
    while(1)
    {
        system("CLS");
        SetConsoleTitle("Logarithm");
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hStdOut, 0x9);


        cout << "\n\n\tThis is the implementation of Logarithm on Big Numbers!";
        SetConsoleTextAttribute(hStdOut, 0x4);
        cout << "\n\t*First number is the one that you want to convert and the second one is the base you want to convert to!";
        SetConsoleTextAttribute(hStdOut, 0x9);
        cout << "\n\n\tNow please enter the numbers (to exit, enter 1 input numbers):\n\n";

        SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN);

        BigInt first=firstInput();

        while(first==zero)
        {
            MessageBox(0," Well, Bi***es be crazy! Re-enter Genius! ", "  Invalid Input ", true);
            first=firstInput();

        }

        if(first==one) mainPage();

        BigInt second=secondInput();

        BigInt result;

        if(first==zero && second==zero)
            mainPage();


        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_BLUE);
        cout << "\n\tResult of Logarithm (Integer Part) is:\n\n\t";

        result=first.logarithm_base(second);

        SetConsoleTextAttribute(hStdOut, 0x02);

        result.printing();
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_GREEN);

        cout << "\n\n\t";
        system("PAUSE");
    }
}


void isPrime()
{
    while(1)
    {
        system("CLS");
        SetConsoleTitle("Checking for Primeness");
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hStdOut, 0x9);


        cout << "\n\n\tThis is the implementation of checking if a Big Number is Prime or not!";

        SetConsoleTextAttribute(hStdOut, 0x9);
        cout << "\n\n\tNow please enter a number (to exit, enter 0 input numbers):\n\n";

        SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN);

        BigInt first=firstInput();

        if(first==zero)
                mainPage();

        while(first<0)
        {
            MessageBox(0," Did you even go to school? Re-enter Genius! ", "  Invalid Input ", true);
            cout << "\t";
            first=firstInput();
        }


        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_BLUE);
        cout << "\n\tResult of Primeness is:\n\n\t";

        SetConsoleTextAttribute(hStdOut, 0x04 | 0x0F);

        if(first.isPrime())
                cout << "\n\tIs Prime! : ) ";

        else    cout << "\n\tIs not Prime! : )";

        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_GREEN);

        cout << "\n\n\t";
        system("PAUSE");
    }
}


void BaseConversion()
{
    while(1)
    {
        system("CLS");
        SetConsoleTitle("Base Conversion");
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hStdOut, 0x9);


        cout << "\n\n\tThis is the implementation of Base Conversion on Big Numbers!";
        SetConsoleTextAttribute(hStdOut, 0x4);
        cout << "\n\t*First number is the one that you want to convert and the second one is the base you want to convert to!";
        //cout << "\n\t**"
        SetConsoleTextAttribute(hStdOut, 0x9);
        cout << "\n\n\tNow please enter the numbers (to exit, enter 0 input numbers):\n\n";

        SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN);

        BigInt first=firstInput();
        BigInt second=secondInput();

        if(first==zero)
            mainPage();

        if(second<0 || second==one)
        {
            MessageBox(0," Sometimes I forget people like you can exist :| ", " Invalid Input ", true);
            second=secondInput();
        }

        BigInt result;


        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_BLUE);
        cout << "\n\tResult of Base Conversion is:\n\n\t";

        if(second==two) result=first.binaryConversion();
        else result=first.baseConversion(second);

        SetConsoleTextAttribute(hStdOut, 0x02);

        result.printing();
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_GREEN);

        cout << "\n\n\t";
        system("PAUSE");
    }
}


void Factorial()
{
    while(1)
    {
        system("CLS");
        SetConsoleTitle("Factorial");
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hStdOut, 0x9);


        cout << "\n\n\tThis is the Factorial of a Big Numbers!";

        SetConsoleTextAttribute(hStdOut, 0x9);
        cout << "\n\n\tNow please enter the desired number to be Factorialised!  (to exit, enter 1 input numbers):\n\n\t";

        SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN);

        BigInt first;
        first=firstInput();

        BigInt result;

        if(first==one)
            mainPage();

        while(first<0)
        {
            MessageBox(0," They didn't teach you nothing at school ", " Invalid Input ", true);
            first=firstInput();
        }

        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_BLUE);
        cout << "\n\tFactorial of the desired number is:\n\n\t";

        result=first.factorial();

        SetConsoleTextAttribute(hStdOut, 0x02);

        result.printing();
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_GREEN);

        cout << "\n\n\t";
        system("PAUSE");
    }
}


void Sine()
{
    while(1)
    {
        system("CLS");
        SetConsoleTitle("Sine Function");
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hStdOut, 0x9);


        cout << "\n\n\tThis is the Sine of a Big Numbers!";

        SetConsoleTextAttribute(hStdOut, 0x9);
        cout << "\n\n\tNow please enter the desired number:  (to exit, enter 0 input numbers):\n\n\t";

        SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN);

        BigInt first;
        first=firstInput();


        if(first==zero)
            mainPage();

        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_BLUE);
        cout << "\n\tSine of the desired number is:\n\n\t";

        SetConsoleTextAttribute(hStdOut, 0x02);

        cout << first.Big_sine();
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_GREEN);

        cout << "\n\n\t";
        system("PAUSE");
    }
}


void Cosine()
{
    while(1)
    {
        system("CLS");
        SetConsoleTitle("Cosine Function");
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hStdOut, 0x9);


        cout << "\n\n\tThis is the Cosine of a Big Numbers!";

        SetConsoleTextAttribute(hStdOut, 0x9);
        cout << "\n\n\tNow please enter the desired number:  (to exit, enter 0 input numbers):\n\n\t";

        SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN);

        BigInt first;
        first=firstInput();

        if(first==zero)
            mainPage();

        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_BLUE);
        cout << "\n\tCosine of the desired number is:\n\n\t";


        SetConsoleTextAttribute(hStdOut, 0x02);

        cout << first.Big_cosine();

        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_GREEN);

        cout << "\n\n\t";
        system("PAUSE");
    }
}


void Tangent()
{
    while(1)
    {
        system("CLS");
        SetConsoleTitle("Tangent Function");
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hStdOut, 0x9);


        cout << "\n\n\tThis is the Tangent of a Big Numbers!";

        SetConsoleTextAttribute(hStdOut, 0x9);
        cout << "\n\n\tNow please enter the desired number:  (to exit, enter 0 input numbers):\n\n\t";

        SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN);

        BigInt first;
        first=firstInput();

        if(first==zero)
            mainPage();

        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_BLUE);
        cout << "\n\tTangent of the desired number is:\n\n\t";

        SetConsoleTextAttribute(hStdOut, 0x02);

        cout << first.Big_tan();
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_GREEN);

        cout << "\n\n\t";
        system("PAUSE");
    }
}


void coTangent()
{
    while(1)
    {
        system("CLS");
        SetConsoleTitle("Cotangent Function");
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hStdOut, 0x9);


        cout << "\n\n\tThis is the Cotangent of a Big Numbers!";

        SetConsoleTextAttribute(hStdOut, 0x9);
        cout << "\n\n\tNow please enter the desired number:  (to exit, enter 0 input numbers):\n\n\t";

        SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN);

        BigInt first;
        first=firstInput();

        if(first==zero)
            mainPage();

        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_BLUE);
        cout << "\n\tCotangent of the desired number is:\n\n\t";

        SetConsoleTextAttribute(hStdOut, 0x02);

        cout << first.Big_cot();
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_GREEN);

        cout << "\n\n\t";
        system("PAUSE");
    }
}


void arcTangent()
{
    while(1)
    {
        system("CLS");
        SetConsoleTitle("Arctangent Function");
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hStdOut, 0x9);


        cout << "\n\n\tThis is the Arctangent of a Big Numbers!";

        SetConsoleTextAttribute(hStdOut, 0x9);
        cout << "\n\n\tNow please enter the desired number:  (to exit, enter 0 input numbers):\n\n\t";

        SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN);

        BigInt first;
        first=firstInput();

        if(first==zero)
            mainPage();

        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_BLUE);
        cout << "\n\tArctangent of the desired number is:\n\n\t";

        SetConsoleTextAttribute(hStdOut, 0x02);

        cout << first.Big_arcTan();
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_GREEN);

        cout << "\n\n\t";
        system("PAUSE");
    }
}


int to_int(string a)
{
    stringstream ss(a);
    int res;

    ss >> res;

    return res;
}


string to_string(int a)
{
    stringstream ss;
    ss << a;
    return ss.str();
}


void reverseStr(string& str)
{
    int n = str.length();

    // Swap character starting from two corners
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}


int main()
{
    aaronCalc();
}




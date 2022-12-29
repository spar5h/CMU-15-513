/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  return ~(~(x & ~y) & ~(~x & y));
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  return 1 << 31;
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  return !(~(x ^ (x + 1))) & !(!(~x));
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  return !(((170 << 24) ^ (170 << 16) ^ (170 << 8) ^ (170)) & (~x));
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return (~x) + 1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  return !((x >> 3) ^ 6) | !((x >> 1) ^ 28);
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  return (y & (~(!!x) + 1)) | (z & (~(!x) + 1));
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  int bx = x >> 31 & 1;
  int by = y >> 31 & 1;
  int vx = x ^ by << 31;
  int vy = y ^ by << 31;
  int bv = !((vy + (~vx + 1)) >> 31);
  return (bx & !by) | (!(bx ^ by) & bv);
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  int f0 = ~x;
  int f1 = (f0 >> 16) & f0;
  int f2 = (f1 >> 8) & f1;
  int f3 = (f2 >> 4) & f2;
  int f4 = (f3 >> 2) & f3;
  int f5 = (f4 >> 1) & f4 & 1;
  return f5;
}

/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  int b0 = ~(x >> 31 & 1) + 1; // all ones if signed bit, all zeros if no signed bit
  int f0 = (x & ~b0) | (~x & b0); // convert negative number to standard form
  
  int b1 = ~(!!(f0 >> 16)) + 1; // all zeros if first 16 bits has all zeros, otherwise all ones
  int v1 = b1 & 16;
  int m1 = (1 << 16) + (~(1) + 1);
  int f1 = ((f0 >> 16) & b1) | ((f0 & m1) & ~b1);

  int b2 = ~(!!(f1 >> 8)) + 1;
  int v2 = b2 & 8;
  int m2 = 255;
  int f2 = ((f1 >> 8) & b2) | ((f1 & m2) & ~b2);

  int b3 = ~(!!(f2 >> 4)) + 1;
  int v3 = b3 & 4;
  int m3 = 15;
  int f3 = ((f2 >> 4) & b3) | ((f2 & m3) & ~b3);

  int b4 = ~(!!(f3 >> 2)) + 1;
  int v4 = b4 & 2;
  int m4 = 3;
  int f4 = ((f3 >> 2) & b4) | ((f3 & m4) & ~b4);

  int b5 = ~(!!(f4 >> 1)) + 1;
  int v5 = b5 & 1;
  // int m5 = 1;
  // int f5 = ((f4 >> 1) & b5) | ((f4 & m5) & ~b5);

  int v = 1 + v1 + v2 + v3 + v4 + v5 + (!!f0);
  return v;
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
  int s = (uf >> 31) & 1;
  int exp = ((uf ^ (s << 31)) >> 23);
  int frac = uf & ((1 << 23) - 1);
  unsigned int res = 0;
  if (exp == 0) { // denormalized
    res = (s << 31) | (frac << 1);
  }
  else if (exp == 255) { // NaN or Inf
    res = uf;
  }
  else { // normalized
    exp = exp + 1;
    if (exp == 255) {
      res = (s << 31) | (255 << 23);
    }
    else {
      res = (s << 31) | (exp << 23) | frac;
    }
  }
  return res;
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
  int s = (uf >> 31) & 1;
  int exp = ((uf ^ (s << 31)) >> 23);
  int net_exp = exp - 128;
  int frac = uf & ((1 << 23) - 1);
  int mb = 1 << 31;
  int inf = 8 << 28;
  int res = 0;
  if (net_exp <= -2) {
    res = 0;
  }
  else if (net_exp == -1) {
    res = 1;
    if (s) {
      res = ~res + 1;
    }
  }
  else if (net_exp >= 32) {
    res = inf;;
  }
  else {
    unsigned int v = ((1 << 23) | frac) << 8;
    int d = 31 - net_exp;
    unsigned int m = v >> d;
    if (m > mb) {
      res = inf;;
    }
    else if (m == mb) {
      if (s) {
        res = mb;
      }
      else
        res = inf;;
    }
    else {
      if (s) {
        res = ~m + 1;
      }
      else {
        res = m;
      }
    }
  }
  return res;
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */

unsigned floatPower2(int x) { // weird timeout issue, changed to 12 seconds
    int res = 0;
    int s = (x >> 31) & 1;
    if (s) {
        if (x >= -23)
          res = 1 << (23 + x);
    }
    else {
      if (x < 128)
        res = (x + 127) << 23;
      else
        res = 2139095040;
    }
    return res;
}

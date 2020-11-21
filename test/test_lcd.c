#include "unity.h"
#include "appLcd.h"
#include "sapi_convert.h"
#include "mock_sapi_lcd.h"

char err = -1;

// ----------- One digit != 0 -----------
void test_OneDigitValueLowPostionDot(void) {
    lcdSendChar_Expect(' ');
    lcdSendChar_Expect(' ');
    lcdSendChar_Expect(' ');
    lcdSendChar_Expect('3');

    err = lcdSendIntFixedDigit( 3, 4, 0 );
    
    TEST_ASSERT_EQUAL_INT8(0, err);
}

void test_OneDigitValueMiddlePostionDot(void) {
    lcdSendChar_Expect(' ');
    lcdSendChar_Expect('0');
    lcdSendChar_Expect('.');
    lcdSendChar_Expect('3');

    lcdSendIntFixedDigit( 3, 4, 1 );
    
    TEST_ASSERT_EQUAL_INT8(0, err);
}   

void test_OneDigitValueHighPostionDot(void) {
    lcdSendChar_Expect('.');
    lcdSendChar_Expect('0');
    lcdSendChar_Expect('0');
    lcdSendChar_Expect('3');

    lcdSendIntFixedDigit( 3, 4, 3 );
    
    TEST_ASSERT_EQUAL_INT8(0, err);
} 
// ----------- One digit != 0 -----------

// -------- More than One digit ---------
void test_MoreThanOneDigitValueLowPostionDot(void) {
    lcdSendChar_Expect(' ');
    lcdSendChar_Expect(' ');
    lcdSendChar_Expect('8');
    lcdSendChar_Expect('5');
    lcdSendChar_Expect('2');

    err = lcdSendIntFixedDigit( 852, 5, 0 );
    
    TEST_ASSERT_EQUAL_INT8(0, err);
}

void test_MoreThanOneDigitValueMiddlePostionDot(void) {
    lcdSendChar_Expect('0');
    lcdSendChar_Expect('.');
    lcdSendChar_Expect('8');
    lcdSendChar_Expect('5');
    lcdSendChar_Expect('2');

    lcdSendIntFixedDigit( 852, 5, 3 );
    
    TEST_ASSERT_EQUAL_INT8(0, err);
}   

void test_MoreThanOneDigitValueHighPostionDot(void) {
    lcdSendChar_Expect('.');
    lcdSendChar_Expect('0');
    lcdSendChar_Expect('8');
    lcdSendChar_Expect('5');
    lcdSendChar_Expect('2');

    lcdSendIntFixedDigit( 852, 5, 4 );
    
    TEST_ASSERT_EQUAL_INT8(0, err);
} 
// -------- More than One digit ---------

// -------- Digit Value equal to Digit argument ---------
void test_DigitValueEqualDigitArgumentLowPostionDot(void) {
    lcdSendChar_Expect('1');
    lcdSendChar_Expect('2');
    lcdSendChar_Expect('3');
    lcdSendChar_Expect('4');
    lcdSendChar_Expect('5');

    err = lcdSendIntFixedDigit( 12345, 5, 0 );
    
    TEST_ASSERT_EQUAL_INT8(0, err);
}

void test_DigitValueEqualDigitArgumentMiddlePostionDot(void) {
    lcdSendChar_Expect('1');
    lcdSendChar_Expect('2');
    lcdSendChar_Expect('3');
    lcdSendChar_Expect('.');
    lcdSendChar_Expect('4');

    lcdSendIntFixedDigit( 1234, 5, 1 ); // Decimal dot takes one digit out
    
    TEST_ASSERT_EQUAL_INT8(0, err);
}   

void test_DigitValueEqualDigitArgumentHighPostionDot(void) {
    lcdSendChar_Expect('.');
    lcdSendChar_Expect('1');
    lcdSendChar_Expect('2');
    lcdSendChar_Expect('3');
    lcdSendChar_Expect('4');

    lcdSendIntFixedDigit( 1234, 5, 4 );
    
    TEST_ASSERT_EQUAL_INT8(0, err);
} 
// -------- More than One digit ---------

// ---------------- Zero ----------------
void test_ZeroValueLowPostionDot(void) {
    lcdSendChar_Expect(' ');
    lcdSendChar_Expect(' ');
    lcdSendChar_Expect(' ');
    lcdSendChar_Expect(' ');
    lcdSendChar_Expect('0');

    err = lcdSendIntFixedDigit( 0, 5, 0 );
    
    TEST_ASSERT_EQUAL_INT8(0, err);
}

void test_ZeroValueMiddlePostionDot(void) {
    lcdSendChar_Expect(' ');
    lcdSendChar_Expect('0');
    lcdSendChar_Expect('.');
    lcdSendChar_Expect('0');
    lcdSendChar_Expect('0');

    lcdSendIntFixedDigit( 0, 5, 2 );
    
    TEST_ASSERT_EQUAL_INT8(0, err);
}   

void test_ZeroValueHighPostionDot(void) {
    lcdSendChar_Expect('.');
    lcdSendChar_Expect('0');
    lcdSendChar_Expect('0');
    lcdSendChar_Expect('0');
    lcdSendChar_Expect('0');

    lcdSendIntFixedDigit( 0, 5, 4 );
    
    TEST_ASSERT_EQUAL_INT8(0, err);
} 
// ---------------- Zero ----------------

// ---------- Error conditions ----------
void test_Error_DotPositionGreaterThanDigit(void) {
    char err = 0;
    err = lcdSendIntFixedDigit( 2, 3, 5 );
    
    TEST_ASSERT_EQUAL_INT8(-1, err);
}

void test_Error_ValueDigitGreaterThanDigit(void) {
    char err = 0;
    err = lcdSendIntFixedDigit( 454, 3, 1 );
    
    TEST_ASSERT_EQUAL_INT8(-1, err);
}

void test_Error_NegativeValue(void) {
    char err = 0;
    err = lcdSendIntFixedDigit( -4, 3, 0 );
    
    TEST_ASSERT_EQUAL_INT8(-1, err);
}
// ---------- Error conditions ----------
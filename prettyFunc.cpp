//#########################################################
//------------------- C++ code : BEGIN -------------------

#include <iostream>
#include <string>

using namespace std;

//==========================================
//------------------------------------------
void foo1 ()
{
        cout << __PRETTY_FUNCTION__ << endl;
}

//------------------------------------------
int foo2 (const string& s1_1, char c1_i)
{
        cout << __PRETTY_FUNCTION__ << endl;
        return 0;
}


//------------------------------------------
template <typename S1, typename S2, typename S3>
void foo3 (const S1& a1_i, S2& a2_i, S3 a3_i)
{
        cout << __PRETTY_FUNCTION__ << endl;
}


//------------------------------------------
template <typename S1, typename S2, typename S3>
void foo4 ()
{
        cout << __PRETTY_FUNCTION__ << endl;
}


//------------------------------------------
template <typename S0, typename S1, typename S2, typename S3>
S0 foo5 (const S1& a1_i, S2& a2_i, S3 a3_i)
{
        cout << __PRETTY_FUNCTION__ << endl;
        return S0 ();
}


//==========================================
class AAA
{
        public :
                //--------------------------
                void fooAAA1_1 ()
                {
                        cout << __PRETTY_FUNCTION__ << endl;
                }
                //--------------------------
                void fooAAA1_2 () const
                {
                        cout << __PRETTY_FUNCTION__ << endl;
                }
                //--------------------------
                static void fooAAA1_3 ()
                {
                        cout << __PRETTY_FUNCTION__ << endl;
                }
                //--------------------------
                int fooAAA2 (const string& s1_1, char c1_i)
                {
                        cout << __PRETTY_FUNCTION__ << endl;
                        return 0;
                }
                //--------------------------
                template <typename S1, typename S2, typename S3>
                void fooAAA3 (const S1& a1_i, S2& a2_i, S3 a3_i)
                {
                        cout << __PRETTY_FUNCTION__ << endl;
                }
                //--------------------------
                template <typename S1, typename S2, typename S3>
                void fooAAA4 ()
                {
                        cout << __PRETTY_FUNCTION__ << endl;
                }
                //--------------------------
                template <typename S0, typename S1, typename S2,
typename S3>
                S0 fooAAA5 (const S1& a1_i, S2& a2_i, S3 a3_i)
                {
                        cout << __PRETTY_FUNCTION__ << endl;
                        return S0 ();
                }
};



//==========================================
template <typename T1, typename T2>
class BBB
{
        public :
                //--------------------------
                void fooBBB1_1 ()
                {
                        cout << __PRETTY_FUNCTION__ << endl;
                }
                //--------------------------
                void fooBBB1_2 () const
                {
                        cout << __PRETTY_FUNCTION__ << endl;
                }
                //--------------------------
                static void fooBBB1_3 ()
                {
                        cout << __PRETTY_FUNCTION__ << endl;
                }
                //--------------------------
                int fooBBB2 (const string& s1_1, char c1_i)
                {
                        cout << __PRETTY_FUNCTION__ << endl;
                        return 0;
                }
                //--------------------------
                template <typename S1, typename S2, typename S3>
                void fooBBB3 (const S1& a1_i, S2& a2_i, S3 a3_i)
                {
                        cout << __PRETTY_FUNCTION__ << endl;
                }
                //--------------------------
                template <typename S1, typename S2, typename S3>
                void fooBBB4 ()
                {
                        cout << __PRETTY_FUNCTION__ << endl;
                }
                //--------------------------
                template <typename S0, typename S1, typename S2,
typename S3>
                S0 fooBBB5 (const S1& a1_i, S2& a2_i, S3 a3_i)
                {
                        cout << __PRETTY_FUNCTION__ << endl;
                        return S0 ();
                }
};

//==========================================
class XXX {};
class YYY {};
class ZZZ {};

//==========================================

int main ()
{
char            char_value      = 'Z';
int             int_value       = 123;
string          string_value    = "ABCDE";
XXX             XXX_value;
YYY             YYY_value;

        //===============================
        cout << endl;
        foo1 ();

        foo2 (string_value, char_value);

        foo3 (string_value, char_value, XXX_value);
        foo3 (YYY_value, char_value, XXX_value);

        foo4<YYY, int, string> ();
        foo4<YYY, XXX, YYY> ();

        foo5<int> (string_value, char_value, XXX_value);
        foo5<YYY> (char_value, int_value, XXX_value);

        //===============================
        cout << endl;

AAA     aaa;
        aaa.fooAAA1_1 ();

        aaa.fooAAA1_2 ();

        aaa.fooAAA1_3 ();

        aaa.fooAAA2 (string_value, char_value);

        aaa.fooAAA3 (string_value, char_value, XXX_value);
        aaa.fooAAA3 (YYY_value, char_value, XXX_value);

//        aaa.template fooAAA4<YYY, int, string> ();
//        aaa.template fooAAA4<YYY, XXX, YYY> ();

//        aaa.template fooAAA5<int> (string_value, char_value, XXX_value);
//        aaa.template fooAAA5<YYY> (char_value, int_value, XXX_value);


        //===============================
        cout << endl;

BBB<int, char>  bbb1;

        bbb1.fooBBB1_1 ();

        bbb1.fooBBB1_2 ();

        bbb1.fooBBB1_3 ();

        bbb1.fooBBB2 (string_value, char_value);

        bbb1.fooBBB3 (string_value, char_value, XXX_value);
        bbb1.fooBBB3 (YYY_value, char_value, XXX_value);

//        bbb1.template fooBBB4<YYY, int, string> ();
//        bbb1.template fooBBB4<YYY, XXX, YYY> ();

//        bbb1.template fooBBB5<int> (string_value, char_value, XXX_value);
//        bbb1.template fooBBB5<YYY> (char_value, int_value, XXX_value);


        //===============================
        cout << endl;

BBB<XXX, int>   bbb2;

        bbb2.fooBBB1_1 ();

        bbb2.fooBBB1_2 ();

        bbb2.fooBBB1_3 ();

        bbb2.fooBBB2 (string_value, char_value);

        bbb2.fooBBB3 (string_value, char_value, XXX_value);
        bbb2.fooBBB3 (YYY_value, char_value, XXX_value);

//        bbb2.template fooBBB4<YYY, int, string> ();
//        bbb2.template fooBBB4<YYY, XXX, YYY> ();

//        bbb2.template fooBBB5<int> (string_value, char_value, XXX_value);
//        bbb2.template fooBBB5<YYY> (char_value, int_value, XXX_value);

        //===============================
        cout << endl;
//        bbb2.template fooBBB5<ZZZ> (bbb1, aaa, bbb2);
        return 0;
}

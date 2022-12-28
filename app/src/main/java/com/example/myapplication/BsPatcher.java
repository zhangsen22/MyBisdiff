package com.example.myapplication;

public class BsPatcher {
    static {
        System.loadLibrary("myapplication");
    }
//    output  old   new
    public static native void bsPatch(String oldApk, String patch, String output);

    public static native int carsh1();
    public static native int carsh2();
    public static void test() {

    }
}

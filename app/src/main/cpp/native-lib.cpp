#include <jni.h>
#include <string>
// java  jvm  C
//    C++
//import static com.maniu.bisdiffmaniu.BsPatcher.test;
extern "C"{
    extern int p_main(int argc, const char *argv[]);
}
struct Person {
    int age;
};
extern "C"
JNIEXPORT void JNICALL
Java_com_example_myapplication_BsPatcher_bsPatch(JNIEnv *env, jclass clazz,jstring oldApk_,
                                              jstring patch_,
                                              jstring output_) {
    const char *oldApk = env->GetStringUTFChars(oldApk_, 0);
    const char *patch = env->GetStringUTFChars(patch_, 0);
    const char *output = env->GetStringUTFChars(output_, 0);
    const char *argv[] = {"", oldApk, output, patch};
//使用他
    p_main(4,argv);
    env->ReleaseStringUTFChars(oldApk_, oldApk);
    env->ReleaseStringUTFChars(patch_, patch);
    env->ReleaseStringUTFChars(output_, output);
}
Person *perosn;
extern "C"
JNIEXPORT jint JNICALL
Java_com_example_myapplication_BsPatcher_carsh1(JNIEnv *env, jclass clazz) {
    return 1;
}
extern "C"
JNIEXPORT jint JNICALL
        Java_com_example_myapplication_BsPatcher_carsh2(JNIEnv *env, jclass clazz) {
//11  空指针   提前释放 0x0  空指针
//在其他地方 已经释放
    int b = perosn->age;

    return 1;
}
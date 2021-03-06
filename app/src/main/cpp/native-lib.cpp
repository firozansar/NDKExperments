#include <jni.h>
#include <string>

//By default, in order to support polymorphism, the C++ compiler modifies the names
// of all the functions you define in your code. This feature is often referred to
// as name mangling. Due to name mangling, calling your C++ functions from Java
// code will lead to errors. To avoid the errors, you can disable name mangling
// by defining your functions inside an extern "C" block.

extern "C" {
//The names of C++ functions that are accessible via JNI must have the following format:
//* They must have a Java_ prefix.
//* They must contain a mangled form of the package name where the dots are replaced with underscores.
//*They must contain the name of the Java class they belong to.

    JNIEXPORT jstring JNICALL
    Java_uk_co_firozansari_ndkexperiments_MainActivity_getndkstring(JNIEnv *env, jobject instance, jstring string) {

        const char *name = (*env).GetStringUTFChars(string, NULL);
        char msg[60] = "Hello ";
        jstring result;

        strcat(msg, name);
        (*env).ReleaseStringUTFChars(string, name);
        puts(msg);
        result = (*env).NewStringUTF(msg);
        return result;

    }

    JNIEXPORT jstring JNICALL
    Java_uk_co_firozansari_ndkexperiments_MainActivity_getNativeKey(JNIEnv *env, jobject instance) {

        return env->NewStringUTF("TmF0aXZlNWVjcmV0UEBzc3cwcmQy");
    }

}
:: compile and link main.cpp
:: run this bat file with VS2013 x64 Cross Tools Command Prompt 
:: alternarive compile&link (it runs slowly)
:: "C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\bin\x86_amd64\CL.exe" /c /EHsc /nologo /IC:\Ceemple\OpenCV4VS\include main.cpp
:: "C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\bin\x86_amd64\link.exe"  /OUT:"brightest.exe" /NOLOGO /LIBPATH:C:\Ceemple\OpenCV4VS\lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib StatTimer.lib clBLAS.lib clFFT.lib opencv_calib3d300.lib opencv_core300.lib opencv_cuda300.lib opencv_cudaarithm300.lib opencv_cudabgsegm300.lib opencv_cudacodec300.lib opencv_cudafeatures2d300.lib opencv_cudafilters300.lib opencv_cudaimgproc300.lib opencv_cudalegacy300.lib opencv_cudaoptflow300.lib opencv_cudastereo300.lib opencv_cudawarping300.lib opencv_cudev300.lib opencv_features2d300.lib opencv_flann300.lib opencv_highgui300.lib opencv_imgcodecs300.lib opencv_imgproc300.lib opencv_ml300.lib opencv_objdetect300.lib opencv_photo300.lib opencv_shape300.lib opencv_stitching300.lib opencv_superres300.lib opencv_ts300.lib opencv_video300.lib opencv_videoio300.lib opencv_videostab300.lib opengl32.lib glu32.lib /MANIFEST /MANIFESTUAC:"level='asInvoker' uiAccess='false'" /manifest:embed /DEBUG /OPT:REF /OPT:ICF /LTCG /TLBID:1 /DYNAMICBASE /NXCOMPAT /MACHINE:X64 MAIN.OBJ



"C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\bin\x86_amd64\CL.exe" /c /IC:\Ceemple\OpenCV4VS\include /Zi /nologo /W3 /WX- /sdl /O2 /Oi /GL /D _MBCS /Gm- /EHsc /MD /GS /Gy /fp:precise /Zc:wchar_t /Zc:forScope  /Gd /TP MAIN.CPP

"C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\bin\x86_amd64\link.exe"  /OUT:"brightest.exe" /NOLOGO /LIBPATH:C:\Ceemple\OpenCV4VS\lib   opencv_core300.lib    opencv_highgui300.lib  opencv_imgproc300.lib  opencv_videoio300.lib  /LTCG main.obj

brightest.exe

.SILENT:

COPTS=/c /GS- /W4

all:   msgBoxA.exe msgBoxW.exe lastErrA.exe lastErrW.exe 

# { lastErr

lastErrA.exe: ../objs/lib/lastErrA.obj ../objs/test/lastErrA.obj 
	link $** /nodefaultlib /subsystem:console /entry:test user32.lib kernel32.lib /out:$@

lastErrW.exe: ../objs/lib/lastErrW.obj ../objs/test/lastErrW.obj 
	link $** /nodefaultlib /subsystem:console /entry:test user32.lib kernel32.lib /out:$@



../objs/lib/lastErrA.obj: ../../lastErr.c ../../lastErr.h
	cl $(COPTS)             ../../lastErr.c                  /Fo$@

../objs/lib/lastErrW.obj: ../../lastErr.c ../../lastErr.h
	cl $(COPTS) -DUNICODE   ../../lastErr.c                  /Fo$@



../objs/test/lastErrA.obj:   ../lastErr.c ../../lastErr.h
	cl $(COPTS)                ../lastErr.c                  /Fo$@

../objs/test/lastErrW.obj:   ../lastErr.c ../../lastErr.h
	cl  $(COPTS) -DUNICODE     ../lastErr.c                  /Fo$@

# }

# { msgBox

msgBoxA.exe: ../objs/lib/msgBoxA.obj ../objs/lib/lastErrA.obj  ../objs/test/msgBoxA.obj 
	link $** /nodefaultlib /subsystem:console /entry:test user32.lib kernel32.lib /out:$@

msgBoxW.exe: ../objs/lib/msgBoxW.obj ../objs/lib/lastErrW.obj ../objs/test/msgBoxW.obj 
	link $** /nodefaultlib /subsystem:console /entry:test user32.lib kernel32.lib /out:$@



../objs/lib/msgBoxA.obj:  ../../msgBox.c ../../msgBox.h
	cl $(COPTS)             ../../msgBox.c                  /Fo$@

../objs/lib/msgBoxW.obj:  ../../msgBox.c ../../msgBox.h
	cl $(COPTS) -DUNICODE   ../../msgBox.c                  /Fo$@



../objs/test/msgBoxA.obj:    ../msgBox.c ../../msgBox.h
	cl $(COPTS)                ../msgBox.c                  /Fo$@

../objs/test/msgBoxW.obj:    ../msgBox.c ../../msgBox.h
	cl  $(COPTS) -DUNICODE     ../msgBox.c                  /Fo$@


# }

clean:
	del ..\objs\lib\*.obj
	del ..\objs\test\*.obj
	del *.exe

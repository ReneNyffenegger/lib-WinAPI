.SILENT:

COPTS=/c /GS- /W4 /source-charset:utf-8

all:   msgBoxA.exe msgBoxW.exe lastErrA.exe lastErrW.exe consoleA.exe consoleW.exe procA.exe procW.exe

# { proc

procA.exe: ../objs/lib/procA.obj ../objs/test/procA.obj ../objs/lib/lastErrA.obj ../objs/lib/msgBoxA.obj ../objs/lib/consoleA.obj
	link $** /nodefaultlib /subsystem:console /entry:test user32.lib kernel32.lib psapi.lib shlwapi.lib /out:$@

procW.exe: ../objs/lib/procW.obj ../objs/test/procW.obj ../objs/lib/lastErrW.obj ../objs/lib/msgBoxW.obj ../objs/lib/consoleA.obj
	link $** /nodefaultlib /subsystem:console /entry:test user32.lib kernel32.lib psapi.lib shlwapi.lib /out:$@


../objs/lib/procA.obj:  ../../proc.c ../../proc.h  ../../lastErr.h
	cl $(COPTS)             ../../proc.c                  /Fo$@

../objs/lib/procW.obj:  ../../proc.c ../../proc.h  ../../lastErr.h
	cl $(COPTS) -DUNICODE   ../../proc.c                  /Fo$@



../objs/test/procA.obj:    ../proc.c ../../proc.h
	cl $(COPTS)                ../proc.c                  /Fo$@

../objs/test/procW.obj:    ../proc.c ../../proc.h
	cl  $(COPTS) -DUNICODE     ../msgBox.c                /Fo$@

# }

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

# { console

consoleA.exe: ../objs/lib/consoleA.obj ../objs/lib/msgBoxA.obj ../objs/lib/lastErrA.obj ../objs/test/consoleA.obj 
	link $** /nodefaultlib /subsystem:console /entry:test user32.lib kernel32.lib /out:$@

consoleW.exe: ../objs/lib/consoleW.obj ../objs/lib/msgBoxW.obj ../objs/lib/lastErrW.obj ../objs/test/consoleW.obj 
	link $** /nodefaultlib /subsystem:console /entry:test user32.lib kernel32.lib /out:$@



../objs/lib/consoleA.obj:  ../../console.c ../../msgBox.h ../../console.h
	cl $(COPTS)              ../../console.c                  /Fo$@

../objs/lib/consoleW.obj:  ../../console.c ../../msgBox.h ../../console.h
	cl $(COPTS) -DUNICODE    ../../console.c                  /Fo$@



../objs/test/consoleA.obj:    ../console.c ../../msgBox.h ../../console.h
	cl $(COPTS)                 ../console.c                  /Fo$@

../objs/test/consoleW.obj:    ../console.c ../../msgBox.h ../../console.h
	cl  $(COPTS) -DUNICODE      ../console.c                  /Fo$@

# }

clean:
	del ..\objs\lib\*.obj
	del ..\objs\test\*.obj
	del *.exe

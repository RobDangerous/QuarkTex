GLvoid _glAccum(GLenum op __asm("d1"), GLfloat value __asm("d2")) {EXEC(Accum);
}
GLvoid _glAlphaFunc(GLenum func __asm("d1"), GLclampf ref __asm("d2")) {EXEC(AlphaFunc);
}
GLboolean _glAreTexturesResident(GLsizei n __asm("d1"), GLuint* textures __asm("d2"), GLboolean* residences __asm("d3")) {EXEC_RET(AreTexturesResident);
return ret; }
GLvoid _glArrayElement(GLint i __asm("d1")) {EXEC(ArrayElement);
}
GLvoid _glBegin(GLenum mode __asm("d1")) {EXEC(Begin);
}
GLvoid _glBindTexture(GLenum target __asm("d1"), GLuint texture __asm("d2")) {EXEC(BindTexture);
}
GLvoid _glBitmap(GLsizei width __asm("d1"), GLsizei height __asm("d2"), GLfloat xorig __asm("d3"), GLfloat yorig __asm("d4"), GLfloat xmove __asm("d5"), GLfloat ymove __asm("d6"), GLubyte* bitmap __asm("d7")) {EXEC(Bitmap);
}
GLvoid _glBlendFunc(GLenum sfactor __asm("d1"), GLenum dfactor __asm("d2")) {EXEC(BlendFunc);
}
GLvoid _glCallList(GLuint list __asm("d1")) {EXEC(CallList);
}
GLvoid _glCallLists(GLsizei n __asm("d1"), GLenum type __asm("d2"), GLvoid* lists __asm("d3")) {EXEC(CallLists);
}
GLvoid _glClear(GLbitfield mask __asm("d1")) {EXEC(Clear);
}
GLvoid _glClearAccum(GLfloat red __asm("d1"), GLfloat green __asm("d2"), GLfloat blue __asm("d3"), GLfloat alpha __asm("d4")) {EXEC(ClearAccum);
}
GLvoid _glClearColor(GLclampf red __asm("d1"), GLclampf green __asm("d2"), GLclampf blue __asm("d3"), GLclampf alpha __asm("d4")) {EXEC(ClearColor);
}
GLvoid _glClearDepth(GLclampd depth __asm("fp0")) {
asm volatile ("
movem.l a2-a6/d2-d7,-(a7)
fmove.d fp0,_fp0
move.l _fp0,d1\nmove.l _fp0,d2
");
EXEC(ClearDepth);
asm volatile ("movem.l (a7)+,a2-a6/d2-d7");
}
GLvoid _glClearIndex(GLfloat c __asm("d1")) {EXEC(ClearIndex);
}
GLvoid _glClearStencil(GLint s __asm("d1")) {EXEC(ClearStencil);
}
GLvoid _glClipPlane(GLenum plane __asm("d1"), GLdouble* equation __asm("d2")) {EXEC(ClipPlane);
}
GLvoid _glColor3b(GLbyte red __asm("d1"), GLbyte green __asm("d2"), GLbyte blue __asm("d3")) {EXEC(Color3b);
}
GLvoid _glColor3bv(GLbyte* v __asm("d1")) {EXEC(Color3bv);
}
GLvoid _glColor3d(GLdouble red __asm("fp0"), GLdouble green __asm("fp1"), GLdouble blue __asm("fp2")) {
asm volatile ("
movem.l a2-a6/d2-d7,-(a7)
fmove.d fp0,_fp0
fmove.d fp1,_fp1
fmove.d fp2,_fp2
move.l _fp0,d1\nmove.l _fp0,d2
move.l _fp1,d3\nmove.l _fp1,d4
move.l _fp2,d5\nmove.l _fp2,d6
");
EXEC(Color3d);
asm volatile ("movem.l (a7)+,a2-a6/d2-d7");
}
GLvoid _glColor3dv(GLdouble* v __asm("d1")) {EXEC(Color3dv);
}
GLvoid _glColor3f(GLfloat red __asm("d1"), GLfloat green __asm("d2"), GLfloat blue __asm("d3")) {EXEC(Color3f);
}
GLvoid _glColor3fv(GLfloat* v __asm("d1")) {EXEC(Color3fv);
}
GLvoid _glColor3i(GLint red __asm("d1"), GLint green __asm("d2"), GLint blue __asm("d3")) {EXEC(Color3i);
}
GLvoid _glColor3iv(GLint* v __asm("d1")) {EXEC(Color3iv);
}
GLvoid _glColor3s(GLshort red __asm("d1"), GLshort green __asm("d2"), GLshort blue __asm("d3")) {EXEC(Color3s);
}
GLvoid _glColor3sv(GLshort* v __asm("d1")) {EXEC(Color3sv);
}
GLvoid _glColor3ub(GLubyte red __asm("d1"), GLubyte green __asm("d2"), GLubyte blue __asm("d3")) {EXEC(Color3ub);
}
GLvoid _glColor3ubv(GLubyte* v __asm("d1")) {EXEC(Color3ubv);
}
GLvoid _glColor3ui(GLuint red __asm("d1"), GLuint green __asm("d2"), GLuint blue __asm("d3")) {EXEC(Color3ui);
}
GLvoid _glColor3uiv(GLuint* v __asm("d1")) {EXEC(Color3uiv);
}
GLvoid _glColor3us(GLushort red __asm("d1"), GLushort green __asm("d2"), GLushort blue __asm("d3")) {EXEC(Color3us);
}
GLvoid _glColor3usv(GLushort* v __asm("d1")) {EXEC(Color3usv);
}
GLvoid _glColor4b(GLbyte red __asm("d1"), GLbyte green __asm("d2"), GLbyte blue __asm("d3"), GLbyte alpha __asm("d4")) {EXEC(Color4b);
}
GLvoid _glColor4bv(GLbyte* v __asm("d1")) {EXEC(Color4bv);
}
GLvoid _glColor4d(GLdouble red __asm("fp0"), GLdouble green __asm("fp1"), GLdouble blue __asm("fp2"), GLdouble alpha __asm("fp3")) {
asm volatile ("
movem.l a2-a6/d2-d7,-(a7)
fmove.d fp0,_fp0
fmove.d fp1,_fp1
fmove.d fp2,_fp2
fmove.d fp3,_fp3
move.l _fp0,d1\nmove.l _fp0,d2
move.l _fp1,d3\nmove.l _fp1,d4
move.l _fp2,d5\nmove.l _fp2,d6
move.l _fp3,d7\nmove.l _fp3,a1
");
EXEC(Color4d);
asm volatile ("movem.l (a7)+,a2-a6/d2-d7");
}
GLvoid _glColor4dv(GLdouble* v __asm("d1")) {EXEC(Color4dv);
}
GLvoid _glColor4f(GLfloat red __asm("d1"), GLfloat green __asm("d2"), GLfloat blue __asm("d3"), GLfloat alpha __asm("d4")) {EXEC(Color4f);
}
GLvoid _glColor4fv(GLfloat* v __asm("d1")) {EXEC(Color4fv);
}
GLvoid _glColor4i(GLint red __asm("d1"), GLint green __asm("d2"), GLint blue __asm("d3"), GLint alpha __asm("d4")) {EXEC(Color4i);
}
GLvoid _glColor4iv(GLint* v __asm("d1")) {EXEC(Color4iv);
}
GLvoid _glColor4s(GLshort red __asm("d1"), GLshort green __asm("d2"), GLshort blue __asm("d3"), GLshort alpha __asm("d4")) {EXEC(Color4s);
}
GLvoid _glColor4sv(GLshort* v __asm("d1")) {EXEC(Color4sv);
}
GLvoid _glColor4ub(GLubyte red __asm("d1"), GLubyte green __asm("d2"), GLubyte blue __asm("d3"), GLubyte alpha __asm("d4")) {EXEC(Color4ub);
}
GLvoid _glColor4ubv(GLubyte* v __asm("d1")) {EXEC(Color4ubv);
}
GLvoid _glColor4ui(GLuint red __asm("d1"), GLuint green __asm("d2"), GLuint blue __asm("d3"), GLuint alpha __asm("d4")) {EXEC(Color4ui);
}
GLvoid _glColor4uiv(GLuint* v __asm("d1")) {EXEC(Color4uiv);
}
GLvoid _glColor4us(GLushort red __asm("d1"), GLushort green __asm("d2"), GLushort blue __asm("d3"), GLushort alpha __asm("d4")) {EXEC(Color4us);
}
GLvoid _glColor4usv(GLushort* v __asm("d1")) {EXEC(Color4usv);
}
GLvoid _glColorMask(GLboolean red __asm("d1"), GLboolean green __asm("d2"), GLboolean blue __asm("d3"), GLboolean alpha __asm("d4")) {EXEC(ColorMask);
}
GLvoid _glColorMaterial(GLenum face __asm("d1"), GLenum mode __asm("d2")) {EXEC(ColorMaterial);
}
GLvoid _glColorPointer(GLint size __asm("d1"), GLenum type __asm("d2"), GLsizei stride __asm("d3"), GLvoid* pointer __asm("d4")) {EXEC(ColorPointer);
}
GLvoid _glCopyPixels(GLint x __asm("d1"), GLint y __asm("d2"), GLsizei width __asm("d3"), GLsizei height __asm("d4"), GLenum type __asm("d5")) {EXEC(CopyPixels);
}
GLvoid _glCopyTexImage1D(GLenum target __asm("d1"), GLint level __asm("d2"), GLenum internalFormat __asm("d3"), GLint x __asm("d4"), GLint y __asm("d5"), GLsizei width __asm("d6"), GLint border __asm("d7")) {EXEC(CopyTexImage1D);
}
GLvoid _glCopyTexImage2D(GLenum target __asm("d1"), GLint level __asm("d2"), GLenum internalFormat __asm("d3"), GLint x __asm("d4"), GLint y __asm("d5"), GLsizei width __asm("d6"), GLsizei height __asm("d7"), GLint border __asm("a1")) {EXEC(CopyTexImage2D);
}
GLvoid _glCopyTexSubImage1D(GLenum target __asm("d1"), GLint level __asm("d2"), GLint xoffset __asm("d3"), GLint x __asm("d4"), GLint y __asm("d5"), GLsizei width __asm("d6")) {EXEC(CopyTexSubImage1D);
}
GLvoid _glCopyTexSubImage2D(GLenum target __asm("d1"), GLint level __asm("d2"), GLint xoffset __asm("d3"), GLint yoffset __asm("d4"), GLint x __asm("d5"), GLint y __asm("d6"), GLsizei width __asm("d7"), GLsizei height __asm("a1")) {EXEC(CopyTexSubImage2D);
}
GLvoid _glCullFace(GLenum mode __asm("d1")) {EXEC(CullFace);
}
GLvoid _glDeleteLists(GLuint list __asm("d1"), GLsizei range __asm("d2")) {EXEC(DeleteLists);
}
GLvoid _glDeleteTextures(GLsizei n __asm("d1"), GLuint* textures __asm("d2")) {EXEC(DeleteTextures);
}
GLvoid _glDepthFunc(GLenum func __asm("d1")) {EXEC(DepthFunc);
}
GLvoid _glDepthMask(GLboolean flag __asm("d1")) {EXEC(DepthMask);
}
GLvoid _glDepthRange(GLclampd zNear __asm("fp0"), GLclampd zFar __asm("fp1")) {
asm volatile ("
movem.l a2-a6/d2-d7,-(a7)
fmove.d fp0,_fp0
fmove.d fp1,_fp1
move.l _fp0,d1\nmove.l _fp0,d2
move.l _fp1,d3\nmove.l _fp1,d4
");
EXEC(DepthRange);
asm volatile ("movem.l (a7)+,a2-a6/d2-d7");
}
GLvoid _glDisable(GLenum cap __asm("d1")) {EXEC(Disable);
}
GLvoid _glDisableClientState(GLenum array __asm("d1")) {EXEC(DisableClientState);
}
GLvoid _glDrawArrays(GLenum mode __asm("d1"), GLint first __asm("d2"), GLsizei count __asm("d3")) {EXEC(DrawArrays);
}
GLvoid _glDrawBuffer(GLenum mode __asm("d1")) {EXEC(DrawBuffer);
}
GLvoid _glDrawElements(GLenum mode __asm("d1"), GLsizei count __asm("d2"), GLenum type __asm("d3"), GLvoid* indices __asm("d4")) {EXEC(DrawElements);
}
GLvoid _glDrawPixels(GLsizei width __asm("d1"), GLsizei height __asm("d2"), GLenum format __asm("d3"), GLenum type __asm("d4"), GLvoid* pixels __asm("d5")) {EXEC(DrawPixels);
}
GLvoid _glEdgeFlag(GLboolean flag __asm("d1")) {EXEC(EdgeFlag);
}
GLvoid _glEdgeFlagPointer(GLsizei stride __asm("d1"), GLvoid* pointer __asm("d2")) {EXEC(EdgeFlagPointer);
}
GLvoid _glEdgeFlagv(GLboolean* flag __asm("d1")) {EXEC(EdgeFlagv);
}
GLvoid _glEnable(GLenum cap __asm("d1")) {EXEC(Enable);
}
GLvoid _glEnableClientState(GLenum array __asm("d1")) {EXEC(EnableClientState);
}
GLvoid _glEnd(void) {EXEC(End);
}
GLvoid _glEndList(void) {EXEC(EndList);
}
GLvoid _glEvalCoord1d(GLdouble u __asm("fp0")) {
asm volatile ("
movem.l a2-a6/d2-d7,-(a7)
fmove.d fp0,_fp0
move.l _fp0,d1\nmove.l _fp0,d2
");
EXEC(EvalCoord1d);
asm volatile ("movem.l (a7)+,a2-a6/d2-d7");
}
GLvoid _glEvalCoord1dv(GLdouble* u __asm("d1")) {EXEC(EvalCoord1dv);
}
GLvoid _glEvalCoord1f(GLfloat u __asm("d1")) {EXEC(EvalCoord1f);
}
GLvoid _glEvalCoord1fv(GLfloat* u __asm("d1")) {EXEC(EvalCoord1fv);
}
GLvoid _glEvalCoord2d(GLdouble u __asm("fp0"), GLdouble v __asm("fp1")) {
asm volatile ("
movem.l a2-a6/d2-d7,-(a7)
fmove.d fp0,_fp0
fmove.d fp1,_fp1
move.l _fp0,d1\nmove.l _fp0,d2
move.l _fp1,d3\nmove.l _fp1,d4
");
EXEC(EvalCoord2d);
asm volatile ("movem.l (a7)+,a2-a6/d2-d7");
}
GLvoid _glEvalCoord2dv(GLdouble* u __asm("d1")) {EXEC(EvalCoord2dv);
}
GLvoid _glEvalCoord2f(GLfloat u __asm("d1"), GLfloat v __asm("d2")) {EXEC(EvalCoord2f);
}
GLvoid _glEvalCoord2fv(GLfloat* u __asm("d1")) {EXEC(EvalCoord2fv);
}
GLvoid _glEvalMesh1(GLenum mode __asm("d1"), GLint i1 __asm("d2"), GLint i2 __asm("d3")) {EXEC(EvalMesh1);
}
GLvoid _glEvalMesh2(GLenum mode __asm("d1"), GLint i1 __asm("d2"), GLint i2 __asm("d3"), GLint j1 __asm("d4"), GLint j2 __asm("d5")) {EXEC(EvalMesh2);
}
GLvoid _glEvalPoint1(GLint i __asm("d1")) {EXEC(EvalPoint1);
}
GLvoid _glEvalPoint2(GLint i __asm("d1"), GLint j __asm("d2")) {EXEC(EvalPoint2);
}
GLvoid _glFeedbackBuffer(GLsizei size __asm("d1"), GLenum type __asm("d2"), GLfloat* buffer __asm("d3")) {EXEC(FeedbackBuffer);
}
GLvoid _glFinish(void) {EXEC(Finish);
}
GLvoid _glFlush(void) {EXEC(Flush);
}
GLvoid _glFogf(GLenum pname __asm("d1"), GLfloat param __asm("d2")) {EXEC(Fogf);
}
GLvoid _glFogfv(GLenum pname __asm("d1"), GLfloat* params __asm("d2")) {EXEC(Fogfv);
}
GLvoid _glFogi(GLenum pname __asm("d1"), GLint param __asm("d2")) {EXEC(Fogi);
}
GLvoid _glFogiv(GLenum pname __asm("d1"), GLint* params __asm("d2")) {EXEC(Fogiv);
}
GLvoid _glFrontFace(GLenum mode __asm("d1")) {EXEC(FrontFace);
}
GLvoid _glFrustum(GLdouble left __asm("fp0"), GLdouble right __asm("fp1"), GLdouble bottom __asm("fp2"), GLdouble top __asm("fp3"), GLdouble zNear __asm("fp4"), GLdouble zFar __asm("fp5")) {
asm volatile ("
movem.l a2-a6/d2-d7,-(a7)
fmove.d fp0,_fp0
fmove.d fp1,_fp1
fmove.d fp2,_fp2
fmove.d fp3,_fp3
fmove.d fp4,_fp4
fmove.d fp5,_fp5
move.l _fp0,d1\nmove.l _fp0,d2
move.l _fp1,d3\nmove.l _fp1,d4
move.l _fp2,d5\nmove.l _fp2,d6
move.l _fp3,d7\nmove.l _fp3,a1
move.l _fp4,a2\nmove.l _fp4,a3
move.l _fp5,a4\nmove.l _fp5,a5
");
EXEC(Frustum);
asm volatile ("movem.l (a7)+,a2-a6/d2-d7");
}
GLuint _glGenLists(GLsizei range __asm("d1")) {EXEC_RET(GenLists);
return ret; }
GLvoid _glGenTextures(GLsizei n __asm("d1"), GLuint* textures __asm("d2")) {EXEC(GenTextures);
}
GLvoid _glGetBooleanv(GLenum pname __asm("d1"), GLboolean* params __asm("d2")) {EXEC(GetBooleanv);
}
GLvoid _glGetClipPlane(GLenum plane __asm("d1"), GLdouble* equation __asm("d2")) {EXEC(GetClipPlane);
}
GLvoid _glGetDoublev(GLenum pname __asm("d1"), GLdouble* params __asm("d2")) {EXEC(GetDoublev);
}
GLenum _glGetError(void) {EXEC_RET(GetError);
return ret; }
GLvoid _glGetFloatv(GLenum pname __asm("d1"), GLfloat* params __asm("d2")) {EXEC(GetFloatv);
}
GLvoid _glGetIntegerv(GLenum pname __asm("d1"), GLint* params __asm("d2")) {EXEC(GetIntegerv);
}
GLvoid _glGetLightfv(GLenum light __asm("d1"), GLenum pname __asm("d2"), GLfloat* params __asm("d3")) {EXEC(GetLightfv);
}
GLvoid _glGetLightiv(GLenum light __asm("d1"), GLenum pname __asm("d2"), GLint* params __asm("d3")) {EXEC(GetLightiv);
}
GLvoid _glGetMapdv(GLenum target __asm("d1"), GLenum query __asm("d2"), GLdouble* v __asm("d3")) {EXEC(GetMapdv);
}
GLvoid _glGetMapfv(GLenum target __asm("d1"), GLenum query __asm("d2"), GLfloat* v __asm("d3")) {EXEC(GetMapfv);
}
GLvoid _glGetMapiv(GLenum target __asm("d1"), GLenum query __asm("d2"), GLint* v __asm("d3")) {EXEC(GetMapiv);
}
GLvoid _glGetMaterialfv(GLenum face __asm("d1"), GLenum pname __asm("d2"), GLfloat* params __asm("d3")) {EXEC(GetMaterialfv);
}
GLvoid _glGetMaterialiv(GLenum face __asm("d1"), GLenum pname __asm("d2"), GLint* params __asm("d3")) {EXEC(GetMaterialiv);
}
GLvoid _glGetPixelMapfv(GLenum map __asm("d1"), GLfloat* values __asm("d2")) {EXEC(GetPixelMapfv);
}
GLvoid _glGetPixelMapuiv(GLenum map __asm("d1"), GLuint* values __asm("d2")) {EXEC(GetPixelMapuiv);
}
GLvoid _glGetPixelMapusv(GLenum map __asm("d1"), GLushort* values __asm("d2")) {EXEC(GetPixelMapusv);
}
GLvoid _glGetPointerv(GLenum pname __asm("d1"), GLvoid** params __asm("d2")) {EXEC(GetPointerv);
}
GLvoid _glGetPolygonStipple(GLubyte* mask __asm("d1")) {EXEC(GetPolygonStipple);
}
GLubyte* _glGetString(GLenum name __asm("d1")) {EXEC_RET(GetString);
return ret; }
GLvoid _glGetTexEnvfv(GLenum target __asm("d1"), GLenum pname __asm("d2"), GLfloat* params __asm("d3")) {EXEC(GetTexEnvfv);
}
GLvoid _glGetTexEnviv(GLenum target __asm("d1"), GLenum pname __asm("d2"), GLint* params __asm("d3")) {EXEC(GetTexEnviv);
}
GLvoid _glGetTexGendv(GLenum coord __asm("d1"), GLenum pname __asm("d2"), GLdouble* params __asm("d3")) {EXEC(GetTexGendv);
}
GLvoid _glGetTexGenfv(GLenum coord __asm("d1"), GLenum pname __asm("d2"), GLfloat* params __asm("d3")) {EXEC(GetTexGenfv);
}
GLvoid _glGetTexGeniv(GLenum coord __asm("d1"), GLenum pname __asm("d2"), GLint* params __asm("d3")) {EXEC(GetTexGeniv);
}
GLvoid _glGetTexImage(GLenum target __asm("d1"), GLint level __asm("d2"), GLenum format __asm("d3"), GLenum type __asm("d4"), GLvoid* pixels __asm("d5")) {EXEC(GetTexImage);
}
GLvoid _glGetTexLevelParameterfv(GLenum target __asm("d1"), GLint level __asm("d2"), GLenum pname __asm("d3"), GLfloat* params __asm("d4")) {EXEC(GetTexLevelParameterfv);
}
GLvoid _glGetTexLevelParameteriv(GLenum target __asm("d1"), GLint level __asm("d2"), GLenum pname __asm("d3"), GLint* params __asm("d4")) {EXEC(GetTexLevelParameteriv);
}
GLvoid _glGetTexParameterfv(GLenum target __asm("d1"), GLenum pname __asm("d2"), GLfloat* params __asm("d3")) {EXEC(GetTexParameterfv);
}
GLvoid _glGetTexParameteriv(GLenum target __asm("d1"), GLenum pname __asm("d2"), GLint* params __asm("d3")) {EXEC(GetTexParameteriv);
}
GLvoid _glHint(GLenum target __asm("d1"), GLenum mode __asm("d2")) {EXEC(Hint);
}
GLvoid _glIndexMask(GLuint mask __asm("d1")) {EXEC(IndexMask);
}
GLvoid _glIndexPointer(GLenum type __asm("d1"), GLsizei stride __asm("d2"), GLvoid* pointer __asm("d3")) {EXEC(IndexPointer);
}
GLvoid _glIndexd(GLdouble c __asm("fp0")) {
asm volatile ("
movem.l a2-a6/d2-d7,-(a7)
fmove.d fp0,_fp0
move.l _fp0,d1\nmove.l _fp0,d2
");
EXEC(Indexd);
asm volatile ("movem.l (a7)+,a2-a6/d2-d7");
}
GLvoid _glIndexdv(GLdouble* c __asm("d1")) {EXEC(Indexdv);
}
GLvoid _glIndexf(GLfloat c __asm("d1")) {EXEC(Indexf);
}
GLvoid _glIndexfv(GLfloat* c __asm("d1")) {EXEC(Indexfv);
}
GLvoid _glIndexi(GLint c __asm("d1")) {EXEC(Indexi);
}
GLvoid _glIndexiv(GLint* c __asm("d1")) {EXEC(Indexiv);
}
GLvoid _glIndexs(GLshort c __asm("d1")) {EXEC(Indexs);
}
GLvoid _glIndexsv(GLshort* c __asm("d1")) {EXEC(Indexsv);
}
GLvoid _glIndexub(GLubyte c __asm("d1")) {EXEC(Indexub);
}
GLvoid _glIndexubv(GLubyte* c __asm("d1")) {EXEC(Indexubv);
}
GLvoid _glInitNames(void) {EXEC(InitNames);
}
GLvoid _glInterleavedArrays(GLenum format __asm("d1"), GLsizei stride __asm("d2"), GLvoid* pointer __asm("d3")) {EXEC(InterleavedArrays);
}
GLboolean _glIsEnabled(GLenum cap __asm("d1")) {EXEC_RET(IsEnabled);
return ret; }
GLboolean _glIsList(GLuint list __asm("d1")) {EXEC_RET(IsList);
return ret; }
GLboolean _glIsTexture(GLuint texture __asm("d1")) {EXEC_RET(IsTexture);
return ret; }
GLvoid _glLightModelf(GLenum pname __asm("d1"), GLfloat param __asm("d2")) {EXEC(LightModelf);
}
GLvoid _glLightModelfv(GLenum pname __asm("d1"), GLfloat* params __asm("d2")) {EXEC(LightModelfv);
}
GLvoid _glLightModeli(GLenum pname __asm("d1"), GLint param __asm("d2")) {EXEC(LightModeli);
}
GLvoid _glLightModeliv(GLenum pname __asm("d1"), GLint* params __asm("d2")) {EXEC(LightModeliv);
}
GLvoid _glLightf(GLenum light __asm("d1"), GLenum pname __asm("d2"), GLfloat param __asm("d3")) {EXEC(Lightf);
}
GLvoid _glLightfv(GLenum light __asm("d1"), GLenum pname __asm("d2"), GLfloat* params __asm("d3")) {EXEC(Lightfv);
}
GLvoid _glLighti(GLenum light __asm("d1"), GLenum pname __asm("d2"), GLint param __asm("d3")) {EXEC(Lighti);
}
GLvoid _glLightiv(GLenum light __asm("d1"), GLenum pname __asm("d2"), GLint* params __asm("d3")) {EXEC(Lightiv);
}
GLvoid _glLineStipple(GLint factor __asm("d1"), GLushort pattern __asm("d2")) {EXEC(LineStipple);
}
GLvoid _glLineWidth(GLfloat width __asm("d1")) {EXEC(LineWidth);
}
GLvoid _glListBase(GLuint base __asm("d1")) {EXEC(ListBase);
}
GLvoid _glLoadIdentity(void) {EXEC(LoadIdentity);
}
GLvoid _glLoadMatrixd(GLdouble* m __asm("d1")) {EXEC(LoadMatrixd);
}
GLvoid _glLoadMatrixf(GLfloat* m __asm("d1")) {EXEC(LoadMatrixf);
}
GLvoid _glLoadName(GLuint name __asm("d1")) {EXEC(LoadName);
}
GLvoid _glLogicOp(GLenum opcode __asm("d1")) {EXEC(LogicOp);
}
GLvoid _glMap1d(GLenum target __asm("d1"), GLdouble u1 __asm("fp0"), GLdouble u2 __asm("fp1"), GLint stride __asm("d6"), GLint order __asm("d7"), GLdouble* points __asm("a1")) {
asm volatile ("
movem.l a2-a6/d2-d7,-(a7)
fmove.d fp0,_fp0
fmove.d fp1,_fp1
move.l _fp0,d2\nmove.l _fp0,d3
move.l _fp1,d4\nmove.l _fp1,d5
");
EXEC(Map1d);
asm volatile ("movem.l (a7)+,a2-a6/d2-d7");
}
GLvoid _glMap1f(GLenum target __asm("d1"), GLfloat u1 __asm("d2"), GLfloat u2 __asm("d3"), GLint stride __asm("d4"), GLint order __asm("d5"), GLfloat* points __asm("d6")) {EXEC(Map1f);
}
GLvoid _glMap2d(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, GLdouble* points) {
}
GLvoid _glMap2f(GLenum target __asm("d1"), GLfloat u1 __asm("d2"), GLfloat u2 __asm("d3"), GLint ustride __asm("d4"), GLint uorder __asm("d5"), GLfloat v1 __asm("d6"), GLfloat v2 __asm("d7"), GLint vstride __asm("a1"), GLint vorder __asm("a2"), GLfloat* points __asm("a3")) {EXEC(Map2f);
}
GLvoid _glMapGrid1d(GLint un __asm("d1"), GLdouble u1 __asm("fp0"), GLdouble u2 __asm("fp1")) {
asm volatile ("
movem.l a2-a6/d2-d7,-(a7)
fmove.d fp0,_fp0
fmove.d fp1,_fp1
move.l _fp0,d2\nmove.l _fp0,d3
move.l _fp1,d4\nmove.l _fp1,d5
");
EXEC(MapGrid1d);
asm volatile ("movem.l (a7)+,a2-a6/d2-d7");
}
GLvoid _glMapGrid1f(GLint un __asm("d1"), GLfloat u1 __asm("d2"), GLfloat u2 __asm("d3")) {EXEC(MapGrid1f);
}
GLvoid _glMapGrid2d(GLint un __asm("d1"), GLdouble u1 __asm("fp0"), GLdouble u2 __asm("fp1"), GLint vn __asm("d6"), GLdouble v1 __asm("fp2"), GLdouble v2 __asm("fp3")) {
asm volatile ("
movem.l a2-a6/d2-d7,-(a7)
fmove.d fp0,_fp0
fmove.d fp1,_fp1
fmove.d fp2,_fp2
fmove.d fp3,_fp3
move.l _fp0,d2\nmove.l _fp0,d3
move.l _fp1,d4\nmove.l _fp1,d5
move.l _fp2,d7\nmove.l _fp2,a1
move.l _fp3,a2\nmove.l _fp3,a3
");
EXEC(MapGrid2d);
asm volatile ("movem.l (a7)+,a2-a6/d2-d7");
}
GLvoid _glMapGrid2f(GLint un __asm("d1"), GLfloat u1 __asm("d2"), GLfloat u2 __asm("d3"), GLint vn __asm("d4"), GLfloat v1 __asm("d5"), GLfloat v2 __asm("d6")) {EXEC(MapGrid2f);
}
GLvoid _glMaterialf(GLenum face __asm("d1"), GLenum pname __asm("d2"), GLfloat param __asm("d3")) {EXEC(Materialf);
}
GLvoid _glMaterialfv(GLenum face __asm("d1"), GLenum pname __asm("d2"), GLfloat* params __asm("d3")) {EXEC(Materialfv);
}
GLvoid _glMateriali(GLenum face __asm("d1"), GLenum pname __asm("d2"), GLint param __asm("d3")) {EXEC(Materiali);
}
GLvoid _glMaterialiv(GLenum face __asm("d1"), GLenum pname __asm("d2"), GLint* params __asm("d3")) {EXEC(Materialiv);
}
GLvoid _glMatrixMode(GLenum mode __asm("d1")) {EXEC(MatrixMode);
}
GLvoid _glMultMatrixd(GLdouble* m __asm("d1")) {EXEC(MultMatrixd);
}
GLvoid _glMultMatrixf(GLfloat* m __asm("d1")) {EXEC(MultMatrixf);
}
GLvoid _glNewList(GLuint list __asm("d1"), GLenum mode __asm("d2")) {EXEC(NewList);
}
GLvoid _glNormal3b(GLbyte nx __asm("d1"), GLbyte ny __asm("d2"), GLbyte nz __asm("d3")) {EXEC(Normal3b);
}
GLvoid _glNormal3bv(GLbyte* v __asm("d1")) {EXEC(Normal3bv);
}
GLvoid _glNormal3d(GLdouble nx __asm("fp0"), GLdouble ny __asm("fp1"), GLdouble nz __asm("fp2")) {
asm volatile ("
movem.l a2-a6/d2-d7,-(a7)
fmove.d fp0,_fp0
fmove.d fp1,_fp1
fmove.d fp2,_fp2
move.l _fp0,d1\nmove.l _fp0,d2
move.l _fp1,d3\nmove.l _fp1,d4
move.l _fp2,d5\nmove.l _fp2,d6
");
EXEC(Normal3d);
asm volatile ("movem.l (a7)+,a2-a6/d2-d7");
}
GLvoid _glNormal3dv(GLdouble* v __asm("d1")) {EXEC(Normal3dv);
}
GLvoid _glNormal3f(GLfloat nx __asm("d1"), GLfloat ny __asm("d2"), GLfloat nz __asm("d3")) {EXEC(Normal3f);
}
GLvoid _glNormal3fv(GLfloat* v __asm("d1")) {EXEC(Normal3fv);
}
GLvoid _glNormal3i(GLint nx __asm("d1"), GLint ny __asm("d2"), GLint nz __asm("d3")) {EXEC(Normal3i);
}
GLvoid _glNormal3iv(GLint* v __asm("d1")) {EXEC(Normal3iv);
}
GLvoid _glNormal3s(GLshort nx __asm("d1"), GLshort ny __asm("d2"), GLshort nz __asm("d3")) {EXEC(Normal3s);
}
GLvoid _glNormal3sv(GLshort* v __asm("d1")) {EXEC(Normal3sv);
}
GLvoid _glNormalPointer(GLenum type __asm("d1"), GLsizei stride __asm("d2"), GLvoid* pointer __asm("d3")) {EXEC(NormalPointer);
}
GLvoid _glOrtho(GLdouble left __asm("fp0"), GLdouble right __asm("fp1"), GLdouble bottom __asm("fp2"), GLdouble top __asm("fp3"), GLdouble zNear __asm("fp4"), GLdouble zFar __asm("fp5")) {
asm volatile ("
movem.l a2-a6/d2-d7,-(a7)
fmove.d fp0,_fp0
fmove.d fp1,_fp1
fmove.d fp2,_fp2
fmove.d fp3,_fp3
fmove.d fp4,_fp4
fmove.d fp5,_fp5
move.l _fp0,d1\nmove.l _fp0,d2
move.l _fp1,d3\nmove.l _fp1,d4
move.l _fp2,d5\nmove.l _fp2,d6
move.l _fp3,d7\nmove.l _fp3,a1
move.l _fp4,a2\nmove.l _fp4,a3
move.l _fp5,a4\nmove.l _fp5,a5
");
EXEC(Ortho);
asm volatile ("movem.l (a7)+,a2-a6/d2-d7");
}
GLvoid _glPassThrough(GLfloat token __asm("d1")) {EXEC(PassThrough);
}
GLvoid _glPixelMapfv(GLenum map __asm("d1"), GLsizei mapsize __asm("d2"), GLfloat* values __asm("d3")) {EXEC(PixelMapfv);
}
GLvoid _glPixelMapuiv(GLenum map __asm("d1"), GLsizei mapsize __asm("d2"), GLuint* values __asm("d3")) {EXEC(PixelMapuiv);
}
GLvoid _glPixelMapusv(GLenum map __asm("d1"), GLsizei mapsize __asm("d2"), GLushort* values __asm("d3")) {EXEC(PixelMapusv);
}
GLvoid _glPixelStoref(GLenum pname __asm("d1"), GLfloat param __asm("d2")) {EXEC(PixelStoref);
}
GLvoid _glPixelStorei(GLenum pname __asm("d1"), GLint param __asm("d2")) {EXEC(PixelStorei);
}
GLvoid _glPixelTransferf(GLenum pname __asm("d1"), GLfloat param __asm("d2")) {EXEC(PixelTransferf);
}
GLvoid _glPixelTransferi(GLenum pname __asm("d1"), GLint param __asm("d2")) {EXEC(PixelTransferi);
}
GLvoid _glPixelZoom(GLfloat xfactor __asm("d1"), GLfloat yfactor __asm("d2")) {EXEC(PixelZoom);
}
GLvoid _glPointSize(GLfloat size __asm("d1")) {EXEC(PointSize);
}
GLvoid _glPolygonMode(GLenum face __asm("d1"), GLenum mode __asm("d2")) {EXEC(PolygonMode);
}
GLvoid _glPolygonOffset(GLfloat factor __asm("d1"), GLfloat units __asm("d2")) {EXEC(PolygonOffset);
}
GLvoid _glPolygonStipple(GLubyte* mask __asm("d1")) {EXEC(PolygonStipple);
}
GLvoid _glPopAttrib(void) {EXEC(PopAttrib);
}
GLvoid _glPopClientAttrib(void) {EXEC(PopClientAttrib);
}
GLvoid _glPopMatrix(void) {EXEC(PopMatrix);
}
GLvoid _glPopName(void) {EXEC(PopName);
}
GLvoid _glPrioritizeTextures(GLsizei n __asm("d1"), GLuint* textures __asm("d2"), GLclampf* priorities __asm("d3")) {EXEC(PrioritizeTextures);
}
GLvoid _glPushAttrib(GLbitfield mask __asm("d1")) {EXEC(PushAttrib);
}
GLvoid _glPushClientAttrib(GLbitfield mask __asm("d1")) {EXEC(PushClientAttrib);
}
GLvoid _glPushMatrix(void) {EXEC(PushMatrix);
}
GLvoid _glPushName(GLuint name __asm("d1")) {EXEC(PushName);
}
GLvoid _glRasterPos2d(GLdouble x __asm("fp0"), GLdouble y __asm("fp1")) {
asm volatile ("
movem.l a2-a6/d2-d7,-(a7)
fmove.d fp0,_fp0
fmove.d fp1,_fp1
move.l _fp0,d1\nmove.l _fp0,d2
move.l _fp1,d3\nmove.l _fp1,d4
");
EXEC(RasterPos2d);
asm volatile ("movem.l (a7)+,a2-a6/d2-d7");
}
GLvoid _glRasterPos2dv(GLdouble* v __asm("d1")) {EXEC(RasterPos2dv);
}
GLvoid _glRasterPos2f(GLfloat x __asm("d1"), GLfloat y __asm("d2")) {EXEC(RasterPos2f);
}
GLvoid _glRasterPos2fv(GLfloat* v __asm("d1")) {EXEC(RasterPos2fv);
}
GLvoid _glRasterPos2i(GLint x __asm("d1"), GLint y __asm("d2")) {EXEC(RasterPos2i);
}
GLvoid _glRasterPos2iv(GLint* v __asm("d1")) {EXEC(RasterPos2iv);
}
GLvoid _glRasterPos2s(GLshort x __asm("d1"), GLshort y __asm("d2")) {EXEC(RasterPos2s);
}
GLvoid _glRasterPos2sv(GLshort* v __asm("d1")) {EXEC(RasterPos2sv);
}
GLvoid _glRasterPos3d(GLdouble x __asm("fp0"), GLdouble y __asm("fp1"), GLdouble z __asm("fp2")) {
asm volatile ("
movem.l a2-a6/d2-d7,-(a7)
fmove.d fp0,_fp0
fmove.d fp1,_fp1
fmove.d fp2,_fp2
move.l _fp0,d1\nmove.l _fp0,d2
move.l _fp1,d3\nmove.l _fp1,d4
move.l _fp2,d5\nmove.l _fp2,d6
");
EXEC(RasterPos3d);
asm volatile ("movem.l (a7)+,a2-a6/d2-d7");
}
GLvoid _glRasterPos3dv(GLdouble* v __asm("d1")) {EXEC(RasterPos3dv);
}
GLvoid _glRasterPos3f(GLfloat x __asm("d1"), GLfloat y __asm("d2"), GLfloat z __asm("d3")) {EXEC(RasterPos3f);
}
GLvoid _glRasterPos3fv(GLfloat* v __asm("d1")) {EXEC(RasterPos3fv);
}
GLvoid _glRasterPos3i(GLint x __asm("d1"), GLint y __asm("d2"), GLint z __asm("d3")) {EXEC(RasterPos3i);
}
GLvoid _glRasterPos3iv(GLint* v __asm("d1")) {EXEC(RasterPos3iv);
}
GLvoid _glRasterPos3s(GLshort x __asm("d1"), GLshort y __asm("d2"), GLshort z __asm("d3")) {EXEC(RasterPos3s);
}
GLvoid _glRasterPos3sv(GLshort* v __asm("d1")) {EXEC(RasterPos3sv);
}
GLvoid _glRasterPos4d(GLdouble x __asm("fp0"), GLdouble y __asm("fp1"), GLdouble z __asm("fp2"), GLdouble w __asm("fp3")) {
asm volatile ("
movem.l a2-a6/d2-d7,-(a7)
fmove.d fp0,_fp0
fmove.d fp1,_fp1
fmove.d fp2,_fp2
fmove.d fp3,_fp3
move.l _fp0,d1\nmove.l _fp0,d2
move.l _fp1,d3\nmove.l _fp1,d4
move.l _fp2,d5\nmove.l _fp2,d6
move.l _fp3,d7\nmove.l _fp3,a1
");
EXEC(RasterPos4d);
asm volatile ("movem.l (a7)+,a2-a6/d2-d7");
}
GLvoid _glRasterPos4dv(GLdouble* v __asm("d1")) {EXEC(RasterPos4dv);
}
GLvoid _glRasterPos4f(GLfloat x __asm("d1"), GLfloat y __asm("d2"), GLfloat z __asm("d3"), GLfloat w __asm("d4")) {EXEC(RasterPos4f);
}
GLvoid _glRasterPos4fv(GLfloat* v __asm("d1")) {EXEC(RasterPos4fv);
}
GLvoid _glRasterPos4i(GLint x __asm("d1"), GLint y __asm("d2"), GLint z __asm("d3"), GLint w __asm("d4")) {EXEC(RasterPos4i);
}
GLvoid _glRasterPos4iv(GLint* v __asm("d1")) {EXEC(RasterPos4iv);
}
GLvoid _glRasterPos4s(GLshort x __asm("d1"), GLshort y __asm("d2"), GLshort z __asm("d3"), GLshort w __asm("d4")) {EXEC(RasterPos4s);
}
GLvoid _glRasterPos4sv(GLshort* v __asm("d1")) {EXEC(RasterPos4sv);
}
GLvoid _glReadBuffer(GLenum mode __asm("d1")) {EXEC(ReadBuffer);
}
GLvoid _glReadPixels(GLint x __asm("d1"), GLint y __asm("d2"), GLsizei width __asm("d3"), GLsizei height __asm("d4"), GLenum format __asm("d5"), GLenum type __asm("d6"), GLvoid* pixels __asm("d7")) {EXEC(ReadPixels);
}
GLvoid _glRectd(GLdouble x1 __asm("fp0"), GLdouble y1 __asm("fp1"), GLdouble x2 __asm("fp2"), GLdouble y2 __asm("fp3")) {
asm volatile ("
movem.l a2-a6/d2-d7,-(a7)
fmove.d fp0,_fp0
fmove.d fp1,_fp1
fmove.d fp2,_fp2
fmove.d fp3,_fp3
move.l _fp0,d1\nmove.l _fp0,d2
move.l _fp1,d3\nmove.l _fp1,d4
move.l _fp2,d5\nmove.l _fp2,d6
move.l _fp3,d7\nmove.l _fp3,a1
");
EXEC(Rectd);
asm volatile ("movem.l (a7)+,a2-a6/d2-d7");
}
GLvoid _glRectdv(GLdouble* v1 __asm("d1"), GLdouble* v2 __asm("d2")) {EXEC(Rectdv);
}
GLvoid _glRectf(GLfloat x1 __asm("d1"), GLfloat y1 __asm("d2"), GLfloat x2 __asm("d3"), GLfloat y2 __asm("d4")) {EXEC(Rectf);
}
GLvoid _glRectfv(GLfloat* v1 __asm("d1"), GLfloat* v2 __asm("d2")) {EXEC(Rectfv);
}
GLvoid _glRecti(GLint x1 __asm("d1"), GLint y1 __asm("d2"), GLint x2 __asm("d3"), GLint y2 __asm("d4")) {EXEC(Recti);
}
GLvoid _glRectiv(GLint* v1 __asm("d1"), GLint* v2 __asm("d2")) {EXEC(Rectiv);
}
GLvoid _glRects(GLshort x1 __asm("d1"), GLshort y1 __asm("d2"), GLshort x2 __asm("d3"), GLshort y2 __asm("d4")) {EXEC(Rects);
}
GLvoid _glRectsv(GLshort* v1 __asm("d1"), GLshort* v2 __asm("d2")) {EXEC(Rectsv);
}
GLint _glRenderMode(GLenum mode __asm("d1")) {EXEC_RET(RenderMode);
return ret; }
GLvoid _glRotated(GLdouble ane __asm("fp0"), GLdouble x __asm("fp1"), GLdouble y __asm("fp2"), GLdouble z __asm("fp3")) {
asm volatile ("
movem.l a2-a6/d2-d7,-(a7)
fmove.d fp0,_fp0
fmove.d fp1,_fp1
fmove.d fp2,_fp2
fmove.d fp3,_fp3
move.l _fp0,d1\nmove.l _fp0,d2
move.l _fp1,d3\nmove.l _fp1,d4
move.l _fp2,d5\nmove.l _fp2,d6
move.l _fp3,d7\nmove.l _fp3,a1
");
EXEC(Rotated);
asm volatile ("movem.l (a7)+,a2-a6/d2-d7");
}
GLvoid _glRotatef(GLfloat ane __asm("d1"), GLfloat x __asm("d2"), GLfloat y __asm("d3"), GLfloat z __asm("d4")) {EXEC(Rotatef);
}
GLvoid _glScaled(GLdouble x __asm("fp0"), GLdouble y __asm("fp1"), GLdouble z __asm("fp2")) {
asm volatile ("
movem.l a2-a6/d2-d7,-(a7)
fmove.d fp0,_fp0
fmove.d fp1,_fp1
fmove.d fp2,_fp2
move.l _fp0,d1\nmove.l _fp0,d2
move.l _fp1,d3\nmove.l _fp1,d4
move.l _fp2,d5\nmove.l _fp2,d6
");
EXEC(Scaled);
asm volatile ("movem.l (a7)+,a2-a6/d2-d7");
}
GLvoid _glScalef(GLfloat x __asm("d1"), GLfloat y __asm("d2"), GLfloat z __asm("d3")) {EXEC(Scalef);
}
GLvoid _glScissor(GLint x __asm("d1"), GLint y __asm("d2"), GLsizei width __asm("d3"), GLsizei height __asm("d4")) {EXEC(Scissor);
}
GLvoid _glSelectBuffer(GLsizei size __asm("d1"), GLuint* buffer __asm("d2")) {EXEC(SelectBuffer);
}
GLvoid _glShadeModel(GLenum mode __asm("d1")) {EXEC(ShadeModel);
}
GLvoid _glStencilFunc(GLenum func __asm("d1"), GLint ref __asm("d2"), GLuint mask __asm("d3")) {EXEC(StencilFunc);
}
GLvoid _glStencilMask(GLuint mask __asm("d1")) {EXEC(StencilMask);
}
GLvoid _glStencilOp(GLenum fail __asm("d1"), GLenum zfail __asm("d2"), GLenum zpass __asm("d3")) {EXEC(StencilOp);
}
GLvoid _glTexCoord1d(GLdouble s __asm("fp0")) {
asm volatile ("
movem.l a2-a6/d2-d7,-(a7)
fmove.d fp0,_fp0
move.l _fp0,d1\nmove.l _fp0,d2
");
EXEC(TexCoord1d);
asm volatile ("movem.l (a7)+,a2-a6/d2-d7");
}
GLvoid _glTexCoord1dv(GLdouble* v __asm("d1")) {EXEC(TexCoord1dv);
}
GLvoid _glTexCoord1f(GLfloat s __asm("d1")) {EXEC(TexCoord1f);
}
GLvoid _glTexCoord1fv(GLfloat* v __asm("d1")) {EXEC(TexCoord1fv);
}
GLvoid _glTexCoord1i(GLint s __asm("d1")) {EXEC(TexCoord1i);
}
GLvoid _glTexCoord1iv(GLint* v __asm("d1")) {EXEC(TexCoord1iv);
}
GLvoid _glTexCoord1s(GLshort s __asm("d1")) {EXEC(TexCoord1s);
}
GLvoid _glTexCoord1sv(GLshort* v __asm("d1")) {EXEC(TexCoord1sv);
}
GLvoid _glTexCoord2d(GLdouble s __asm("fp0"), GLdouble t __asm("fp1")) {
asm volatile ("
movem.l a2-a6/d2-d7,-(a7)
fmove.d fp0,_fp0
fmove.d fp1,_fp1
move.l _fp0,d1\nmove.l _fp0,d2
move.l _fp1,d3\nmove.l _fp1,d4
");
EXEC(TexCoord2d);
asm volatile ("movem.l (a7)+,a2-a6/d2-d7");
}
GLvoid _glTexCoord2dv(GLdouble* v __asm("d1")) {EXEC(TexCoord2dv);
}
GLvoid _glTexCoord2f(GLfloat s __asm("d1"), GLfloat t __asm("d2")) {EXEC(TexCoord2f);
}
GLvoid _glTexCoord2fv(GLfloat* v __asm("d1")) {EXEC(TexCoord2fv);
}
GLvoid _glTexCoord2i(GLint s __asm("d1"), GLint t __asm("d2")) {EXEC(TexCoord2i);
}
GLvoid _glTexCoord2iv(GLint* v __asm("d1")) {EXEC(TexCoord2iv);
}
GLvoid _glTexCoord2s(GLshort s __asm("d1"), GLshort t __asm("d2")) {EXEC(TexCoord2s);
}
GLvoid _glTexCoord2sv(GLshort* v __asm("d1")) {EXEC(TexCoord2sv);
}
GLvoid _glTexCoord3d(GLdouble s __asm("fp0"), GLdouble t __asm("fp1"), GLdouble r __asm("fp2")) {
asm volatile ("
movem.l a2-a6/d2-d7,-(a7)
fmove.d fp0,_fp0
fmove.d fp1,_fp1
fmove.d fp2,_fp2
move.l _fp0,d1\nmove.l _fp0,d2
move.l _fp1,d3\nmove.l _fp1,d4
move.l _fp2,d5\nmove.l _fp2,d6
");
EXEC(TexCoord3d);
asm volatile ("movem.l (a7)+,a2-a6/d2-d7");
}
GLvoid _glTexCoord3dv(GLdouble* v __asm("d1")) {EXEC(TexCoord3dv);
}
GLvoid _glTexCoord3f(GLfloat s __asm("d1"), GLfloat t __asm("d2"), GLfloat r __asm("d3")) {EXEC(TexCoord3f);
}
GLvoid _glTexCoord3fv(GLfloat* v __asm("d1")) {EXEC(TexCoord3fv);
}
GLvoid _glTexCoord3i(GLint s __asm("d1"), GLint t __asm("d2"), GLint r __asm("d3")) {EXEC(TexCoord3i);
}
GLvoid _glTexCoord3iv(GLint* v __asm("d1")) {EXEC(TexCoord3iv);
}
GLvoid _glTexCoord3s(GLshort s __asm("d1"), GLshort t __asm("d2"), GLshort r __asm("d3")) {EXEC(TexCoord3s);
}
GLvoid _glTexCoord3sv(GLshort* v __asm("d1")) {EXEC(TexCoord3sv);
}
GLvoid _glTexCoord4d(GLdouble s __asm("fp0"), GLdouble t __asm("fp1"), GLdouble r __asm("fp2"), GLdouble q __asm("fp3")) {
asm volatile ("
movem.l a2-a6/d2-d7,-(a7)
fmove.d fp0,_fp0
fmove.d fp1,_fp1
fmove.d fp2,_fp2
fmove.d fp3,_fp3
move.l _fp0,d1\nmove.l _fp0,d2
move.l _fp1,d3\nmove.l _fp1,d4
move.l _fp2,d5\nmove.l _fp2,d6
move.l _fp3,d7\nmove.l _fp3,a1
");
EXEC(TexCoord4d);
asm volatile ("movem.l (a7)+,a2-a6/d2-d7");
}
GLvoid _glTexCoord4dv(GLdouble* v __asm("d1")) {EXEC(TexCoord4dv);
}
GLvoid _glTexCoord4f(GLfloat s __asm("d1"), GLfloat t __asm("d2"), GLfloat r __asm("d3"), GLfloat q __asm("d4")) {EXEC(TexCoord4f);
}
GLvoid _glTexCoord4fv(GLfloat* v __asm("d1")) {EXEC(TexCoord4fv);
}
GLvoid _glTexCoord4i(GLint s __asm("d1"), GLint t __asm("d2"), GLint r __asm("d3"), GLint q __asm("d4")) {EXEC(TexCoord4i);
}
GLvoid _glTexCoord4iv(GLint* v __asm("d1")) {EXEC(TexCoord4iv);
}
GLvoid _glTexCoord4s(GLshort s __asm("d1"), GLshort t __asm("d2"), GLshort r __asm("d3"), GLshort q __asm("d4")) {EXEC(TexCoord4s);
}
GLvoid _glTexCoord4sv(GLshort* v __asm("d1")) {EXEC(TexCoord4sv);
}
GLvoid _glTexCoordPointer(GLint size __asm("d1"), GLenum type __asm("d2"), GLsizei stride __asm("d3"), GLvoid* pointer __asm("d4")) {EXEC(TexCoordPointer);
}
GLvoid _glTexEnvf(GLenum target __asm("d1"), GLenum pname __asm("d2"), GLfloat param __asm("d3")) {EXEC(TexEnvf);
}
GLvoid _glTexEnvfv(GLenum target __asm("d1"), GLenum pname __asm("d2"), GLfloat* params __asm("d3")) {EXEC(TexEnvfv);
}
GLvoid _glTexEnvi(GLenum target __asm("d1"), GLenum pname __asm("d2"), GLint param __asm("d3")) {EXEC(TexEnvi);
}
GLvoid _glTexEnviv(GLenum target __asm("d1"), GLenum pname __asm("d2"), GLint* params __asm("d3")) {EXEC(TexEnviv);
}
GLvoid _glTexGend(GLenum coord __asm("d1"), GLenum pname __asm("d2"), GLdouble param __asm("fp0")) {
asm volatile ("
movem.l a2-a6/d2-d7,-(a7)
fmove.d fp0,_fp0
move.l _fp0,d3\nmove.l _fp0,d4
");
EXEC(TexGend);
asm volatile ("movem.l (a7)+,a2-a6/d2-d7");
}
GLvoid _glTexGendv(GLenum coord __asm("d1"), GLenum pname __asm("d2"), GLdouble* params __asm("d3")) {EXEC(TexGendv);
}
GLvoid _glTexGenf(GLenum coord __asm("d1"), GLenum pname __asm("d2"), GLfloat param __asm("d3")) {EXEC(TexGenf);
}
GLvoid _glTexGenfv(GLenum coord __asm("d1"), GLenum pname __asm("d2"), GLfloat* params __asm("d3")) {EXEC(TexGenfv);
}
GLvoid _glTexGeni(GLenum coord __asm("d1"), GLenum pname __asm("d2"), GLint param __asm("d3")) {EXEC(TexGeni);
}
GLvoid _glTexGeniv(GLenum coord __asm("d1"), GLenum pname __asm("d2"), GLint* params __asm("d3")) {EXEC(TexGeniv);
}
GLvoid _glTexImage1D(GLenum target __asm("d1"), GLint level __asm("d2"), GLint internalformat __asm("d3"), GLsizei width __asm("d4"), GLint border __asm("d5"), GLenum format __asm("d6"), GLenum type __asm("d7"), GLvoid* pixels __asm("a1")) {EXEC(TexImage1D);
}
GLvoid _glTexImage2D(GLenum target __asm("d1"), GLint level __asm("d2"), GLint internalformat __asm("d3"), GLsizei width __asm("d4"), GLsizei height __asm("d5"), GLint border __asm("d6"), GLenum format __asm("d7"), GLenum type __asm("a1"), GLvoid* pixels __asm("a2")) {EXEC(TexImage2D);
}
GLvoid _glTexParameterf(GLenum target __asm("d1"), GLenum pname __asm("d2"), GLfloat param __asm("d3")) {EXEC(TexParameterf);
}
GLvoid _glTexParameterfv(GLenum target __asm("d1"), GLenum pname __asm("d2"), GLfloat* params __asm("d3")) {EXEC(TexParameterfv);
}
GLvoid _glTexParameteri(GLenum target __asm("d1"), GLenum pname __asm("d2"), GLint param __asm("d3")) {EXEC(TexParameteri);
}
GLvoid _glTexParameteriv(GLenum target __asm("d1"), GLenum pname __asm("d2"), GLint* params __asm("d3")) {EXEC(TexParameteriv);
}
GLvoid _glTexSubImage1D(GLenum target __asm("d1"), GLint level __asm("d2"), GLint xoffset __asm("d3"), GLsizei width __asm("d4"), GLenum format __asm("d5"), GLenum type __asm("d6"), GLvoid* pixels __asm("d7")) {EXEC(TexSubImage1D);
}
GLvoid _glTexSubImage2D(GLenum target __asm("d1"), GLint level __asm("d2"), GLint xoffset __asm("d3"), GLint yoffset __asm("d4"), GLsizei width __asm("d5"), GLsizei height __asm("d6"), GLenum format __asm("d7"), GLenum type __asm("a1"), GLvoid* pixels __asm("a2")) {EXEC(TexSubImage2D);
}
GLvoid _glTranslated(GLdouble x __asm("fp0"), GLdouble y __asm("fp1"), GLdouble z __asm("fp2")) {
asm volatile ("
movem.l a2-a6/d2-d7,-(a7)
fmove.d fp0,_fp0
fmove.d fp1,_fp1
fmove.d fp2,_fp2
move.l _fp0,d1\nmove.l _fp0,d2
move.l _fp1,d3\nmove.l _fp1,d4
move.l _fp2,d5\nmove.l _fp2,d6
");
EXEC(Translated);
asm volatile ("movem.l (a7)+,a2-a6/d2-d7");
}
GLvoid _glTranslatef(GLfloat x __asm("d1"), GLfloat y __asm("d2"), GLfloat z __asm("d3")) {EXEC(Translatef);
}
GLvoid _glVertex2d(GLdouble x __asm("fp0"), GLdouble y __asm("fp1")) {
asm volatile ("
movem.l a2-a6/d2-d7,-(a7)
fmove.d fp0,_fp0
fmove.d fp1,_fp1
move.l _fp0,d1\nmove.l _fp0,d2
move.l _fp1,d3\nmove.l _fp1,d4
");
EXEC(Vertex2d);
asm volatile ("movem.l (a7)+,a2-a6/d2-d7");
}
GLvoid _glVertex2dv(GLdouble* v __asm("d1")) {EXEC(Vertex2dv);
}
GLvoid _glVertex2f(GLfloat x __asm("d1"), GLfloat y __asm("d2")) {EXEC(Vertex2f);
}
GLvoid _glVertex2fv(GLfloat* v __asm("d1")) {EXEC(Vertex2fv);
}
GLvoid _glVertex2i(GLint x __asm("d1"), GLint y __asm("d2")) {EXEC(Vertex2i);
}
GLvoid _glVertex2iv(GLint* v __asm("d1")) {EXEC(Vertex2iv);
}
GLvoid _glVertex2s(GLshort x __asm("d1"), GLshort y __asm("d2")) {EXEC(Vertex2s);
}
GLvoid _glVertex2sv(GLshort* v __asm("d1")) {EXEC(Vertex2sv);
}
GLvoid _glVertex3d(GLdouble x __asm("fp0"), GLdouble y __asm("fp1"), GLdouble z __asm("fp2")) {
asm volatile ("
movem.l a2-a6/d2-d7,-(a7)
fmove.d fp0,_fp0
fmove.d fp1,_fp1
fmove.d fp2,_fp2
move.l _fp0,d1\nmove.l _fp0,d2
move.l _fp1,d3\nmove.l _fp1,d4
move.l _fp2,d5\nmove.l _fp2,d6
");
EXEC(Vertex3d);
asm volatile ("movem.l (a7)+,a2-a6/d2-d7");
}
GLvoid _glVertex3dv(GLdouble* v __asm("d1")) {EXEC(Vertex3dv);
}
GLvoid _glVertex3f(GLfloat x __asm("d1"), GLfloat y __asm("d2"), GLfloat z __asm("d3")) {EXEC(Vertex3f);
}
GLvoid _glVertex3fv(GLfloat* v __asm("d1")) {EXEC(Vertex3fv);
}
GLvoid _glVertex3i(GLint x __asm("d1"), GLint y __asm("d2"), GLint z __asm("d3")) {EXEC(Vertex3i);
}
GLvoid _glVertex3iv(GLint* v __asm("d1")) {EXEC(Vertex3iv);
}
GLvoid _glVertex3s(GLshort x __asm("d1"), GLshort y __asm("d2"), GLshort z __asm("d3")) {EXEC(Vertex3s);
}
GLvoid _glVertex3sv(GLshort* v __asm("d1")) {EXEC(Vertex3sv);
}
GLvoid _glVertex4d(GLdouble x __asm("fp0"), GLdouble y __asm("fp1"), GLdouble z __asm("fp2"), GLdouble w __asm("fp3")) {
asm volatile ("
movem.l a2-a6/d2-d7,-(a7)
fmove.d fp0,_fp0
fmove.d fp1,_fp1
fmove.d fp2,_fp2
fmove.d fp3,_fp3
move.l _fp0,d1\nmove.l _fp0,d2
move.l _fp1,d3\nmove.l _fp1,d4
move.l _fp2,d5\nmove.l _fp2,d6
move.l _fp3,d7\nmove.l _fp3,a1
");
EXEC(Vertex4d);
asm volatile ("movem.l (a7)+,a2-a6/d2-d7");
}
GLvoid _glVertex4dv(GLdouble* v __asm("d1")) {EXEC(Vertex4dv);
}
GLvoid _glVertex4f(GLfloat x __asm("d1"), GLfloat y __asm("d2"), GLfloat z __asm("d3"), GLfloat w __asm("d4")) {EXEC(Vertex4f);
}
GLvoid _glVertex4fv(GLfloat* v __asm("d1")) {EXEC(Vertex4fv);
}
GLvoid _glVertex4i(GLint x __asm("d1"), GLint y __asm("d2"), GLint z __asm("d3"), GLint w __asm("d4")) {EXEC(Vertex4i);
}
GLvoid _glVertex4iv(GLint* v __asm("d1")) {EXEC(Vertex4iv);
}
GLvoid _glVertex4s(GLshort x __asm("d1"), GLshort y __asm("d2"), GLshort z __asm("d3"), GLshort w __asm("d4")) {EXEC(Vertex4s);
}
GLvoid _glVertex4sv(GLshort* v __asm("d1")) {EXEC(Vertex4sv);
}
GLvoid _glVertexPointer(GLint size __asm("d1"), GLenum type __asm("d2"), GLsizei stride __asm("d3"), GLvoid* pointer __asm("d4")) {EXEC(VertexPointer);
}
GLvoid _glViewport(GLint x __asm("d1"), GLint y __asm("d2"), GLsizei width __asm("d3"), GLsizei height __asm("d4")) {EXEC(Viewport);
}

import subprocess
import os

# SConscript('color_SConscript')
# Import( 'env' )

ROOTCFLAGS    	= subprocess.check_output( ['root-config',  '--cflags'] ).rstrip().split( " " )
# ROOTLDFLAGS    	= subprocess.check_output( ["root-config",  "--ldflags"] )
# ROOTLIBS      	= subprocess.check_output( ["root-config",  "--libs"] )
# ROOTGLIBS     	= subprocess.check_output( ["root-config",  "--glibs"] )
# ROOTLIBPATH 	= subprocess.check_output( ["root-config", "--libdir" ] )

ROOT_SYS 		= os.environ[ "ROOTSYS" ]
# JDB_LIB			= os.environ[ "JDB_LIB" ]
# JDB_LIB_NAME 	= 'libRooBarb.a'

cppDefines 		= {}
cppFlags 		= ['-Wall' ]#, '-Werror']
cxxFlags 		= ['-std=c++11' ]
cxxFlags.extend( ROOTCFLAGS )

paths 			= [ '.', 			# dont really like this but ended up needing for root dict to work ok
					ROOT_SYS + "/include",
					]

########################### ROOT dictionary creation ##########################
LD_LIBRARY_PATH = os.environ.get( "LD_LIBRARY_PATH", "" )


rootcint_env = Environment(ENV = {'PATH' : os.environ['PATH'], 'ROOTSYS' : os.environ[ "ROOTSYS" ], 'LD_LIBRARY_PATH' : LD_LIBRARY_PATH })
rootcint = Builder( action='rootcint -f $TARGET -c $_CPPINCFLAGS $SOURCES.file' )  
rootcint_env.Append( BUILDERS 		= { 'RootCint' : rootcint } )

# hack to make the rootcint use abs path to headers
rootcint_env[ "_CPPINCFLAGS" ] = "-I" + Dir(".").abspath + "/"
# print rootcint_env[ "_CPPINCFLAGS" ]
root_dict = rootcint_env.RootCint( "DictionaryFemtoDst.cpp", Glob( "Femto*.h" ) )
Clean( root_dict, "DictionaryFemtoDst.h" )
rootcint_env.Alias( 'dict', root_dict )
# .Net Concepts

### .Net framework : 
- The .Net framework is a software development platform developed by Microsoft. The framework was meant to create applications, which would run on the Windows Platform.
- Can be used to developed both web based and form based applications.
- Supports basic languages like Visual basic and C#.
- It helps to write:  
  1. Windows applications
  2. Web applications
  3. Web services

<p align="center">
  <img src="../images/NET-ARCHITECTURE.png" alt="Sample Image" width="800" height="500">
</p>

- Following are some of the components of the .Net framework -
  1. Common Language Runtime (CLR)
  2. The .Net Framework Class Library
  3. Common Language Specification
  4. Common Type System
  5. Metadata and Assemblies
  6. Windows Forms
  7. ASP.Net and ASP.Net AJAX
  8. ADO.Net
  9. Windows Workflow Foundation (WF)
  10. Windows Presentation Foundation 
  11. Windows Communication Foundation (WCF)
  12. LINQ


***

### .Net Components.
1. CLR
2. Framework and Libraries
3. Language

***
### CLR (Common Language Runtime)

<p align="center">
  <img src="../images/Architecture-of-Common-Language-RuntimeCLR.png" alt="Sample Image" width="600" height="500">
</p>

- Platform or a layer between operating system and application where .Net programs are executed.
- Converts Managed code to Native code.
- ***Managed Code*** :	Managed code is code that's written in a managed language (C#, VB.NET, F# and many others) that's compiled into CIL (Common Intermediate Language, formerly Microsoft Intermediate Language or MSIL)(Platform Independent).
- ***MSIL*** : Microsoft Intermediate Language.During the compile time , the compiler convert the source code into Microsoft Intermediate Language (MSIL). MSIL is a CPU-independent set of instructions that can be efficiently converted to the native code (Similar to assembly code instruction).
- ***Native Code*** : It the code generated by the CLR which can be understandable by the OS (Platform Dependent).		         		
- ***JIT*** : During runtime the CIL is interpreted into machine code or Native Code(which is specific to the architecture you're on) and then it's executed. This process is called Just In Time compilation or JIT for short. Only the IL that is needed is transformed into machine code, just in time before it's executed, hence the name JIT.
	- Pre JIT  	- All Code is integrated into executable (slow)
	- Econo JIT	- Only Callable code in integrated into executable (has to done many time as per required)
    - Normal JIT	- Only Callable code is integrated into executable and stored into cache mem.(Hence no need to make executable again hence fast)

  - Features of the CLR
    1. Exception handling : Errors thrown when running a application
	2. Garbage Collection : Removes all the unwanted resources when they are no longer required. 
	3. CTS
	4. CLS
	5. Code Manager
	6. Class Loader

*** 

###  Framework Class Libraries 
- The Framework class library (FCL) is a comprehensive collection of reusable types including classes, interfaces and data types included in the .NET Framework to provide access to system functionality.
- It can be used for developing applications such as console applications, Windows GUI applications, ASP.NET applications, Windows and Web services, workflow-enabled applications, service oriented applications using Windows Communication, XML Web services, etc.
- The reusable types of FCL provide a simple interface to developers due to:
	- Their self-documenting nature.
	- Lesser learning curve to understand the framework, which expedites and optimizes the development process.
	- Seamless integration of third-party components with classes in FCL.
- The .NET FCL is the key component of .NET framework. It provides core functionalities of .NET architecture, which include:
	- Base data types
	- Object type
	- Implementation of data structures
	- Garbage collection
	- Security, data access and database connectivity
	- Network communications
	- Support for implementing rich client GUI for both Windows and Web-based applications
  
- Most of the methods are split into either the System.* or Microsoft.* namespaces.

    - System.* indicates stuff that is logically part of the framework.  It is 100% supported, solid-long term design that will not need to churn, safe to bet on, stable, likely will get great tooling support.  Designed to be very interoperable and could work anywhere .NET is.  This may ship as part of the redist or maybe an out of band (such as ASP.NET MVC, ASP.NET AJAX, etc).
	- Microsoft.* is the bleeding edge stuff or value-add.  It is typically very cool stuff that adds on to the framework and enhances it, but maybe a work in progress... over time you might expect some of those concepts to go into the framework.    As an example, the great work patterns and practices does often falls into this bucket.

*** 

### Languages 
- ***WinForms*** :
  -  This is used for developing Forms-based applications, which would run on an end user machine. Notepad is an example of a client-based application.
- ***ASP .Net*** :
  -  This is used for developing web-based applications, which are made to run on any browser such as Internet Explorer, Chrome or Firefox. The Web application would be processed on a server, which would have Internet Information Services Installed.Internet Information Services or IIS is a Microsoft component which is used to execute an Asp.Net application.The result of the execution is then sent to the client machines, and the output is shown in the browser.
- ***ADO .Net*** :
  -  This technology is used to develop applications to interact with Databases such as Oracle or Microsoft SQL Server.	

***

### Managed c++ :

- When not specified, C++ is unmanaged C++, compiled to machine code. In unmanaged C++ you must manage memory allocation manually.
- Managed C++ is a language invented by Microsoft, that compiles to bytecode run by the .NET Framework. It uses mostly the same syntax
as C++ (hence the name) but is compiled in the same way as C# or VB.NET
- You can code native C++ two different ways. The first is compiling directly to machine code with just the operating system between you and the Platform. The second native coding is done with MFC ( Microsoft Foundation Classes ). This is the same as the first example except for the use of MFC.
- Managed C++ uses the CLR ( Common Language Runtime ) The CLR along with the .net framework class libraries make up the .NET Framework. This managed C++/CLI standard uses the .Net framework along with the MSIL ( Microsoft Intermediate Language ).
- This standard works by mapping to machine code only when the program is executing by the use of a just in time compiler. If your code will be running on different hardware platforms the use of managed code will be much easier. As with all thing there is a slight price to pay for convenience, as native code will run faster.
- Use the managed C++ when we need to mix native C++ and .net code. C++/CLI can be used as the bridge between them.
  
***

C++/CLI : Common Language Infrastructure.

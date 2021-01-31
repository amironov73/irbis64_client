@echo off

del irbis64_client.lib 2> nul
del irbis64_client.exp 2> nul
lib /def:irbis64_client.def /out:irbis64_client.lib /machine:x86
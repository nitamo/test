//TinyHttpd.java
//Tiny HTTP server
//Page 479

import java.net.*;
import java.io.*;
import java.util.concurrent.*;

public class TinyHttpd {
	public static void main(String[] args) {
		Executor executor = Executors.newFixedThreadPool(3);
		ServerSocket serverSocket = new ServerSocket(Integer.parseInt(argv[0]));
		while ( true )
			executor.execute(new TinyHttpdConnection( serverSocket.accept() ) );
	}
}

public class TinyHttpdConnection implements Runnable {
	Socket client;
	
	TinyHttpdConnection( Socket client ) {
		this.client = client;
	}
	
	public void run() {
		try {
			BufferedReader in = new BufferedReader(new InputStreamReader( client.getInputStream(), "8859_1"));
			OutputStream out = client.getOutputStream();
			PrintWriter pout = new PrintWriter(new OutputStreamWriter(out, "8859_1"), true);
			String request = in.readLine();
			System.out.println("Request: " + request);
		}	
	}
}

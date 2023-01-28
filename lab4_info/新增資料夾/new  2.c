
int dfs(int psum, char** M,int i,int j,char dir){
	int x, y, ssum, enQ;
	char sdir;
	ssum = 0;
	x = i;
	y = j;
	
	//determine the searching direction
	/*switch(dir){
	case 'N':
		sdir = 'S';		break;
	case 'E':
		sdir = 'W';		break;
	case 'S':
		sdir = 'N';		break;
	case 'W':
		sdir = 'E';		break;
	default:
		sdir = 'Z';
	}*/
	
		switch(dir){
		case 'N':
			while(M[x][y-1]==' '){
				ssum++;
				if(psum+ssum>MIN){
					enQ = 0;
				}else{
				if(M[x+1][y]==' '){	
					enQ = dfs(psum+ssum,M, x+1, y, 'E');
				}else if(M[x-1][y]=' '){
					enQ = dfs(psum+ssum,M, x-1, y, 'W');
				}
				}
				y--;
			}
			
			if(M[x][y-1]=='X'){
				MIN = psum+ssum;
				enQ = 1;
			} else {
				enQ = 0;
			}

			break;
		case 'E':
			
			break;
		case 'S':
			
			break;
		case 'W':
			
			break;
		default:
			break;
		}

		return enQ;
}
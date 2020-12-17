
window.onscroll = function(){this.shrinkHeader()};
window.onload = function(){this.init()}

// reset to top of page so init doesn't break
window.onbeforeunload = function(){window.scrollTo(0,0);}

// init function sets the padding relative to the height of the header div
function init() {
    var content = document.getElementById("content");
    var header = document.getElementById("header");
    var headheight = header.offsetHeight;
    content.style.paddingTop = `${headheight}px`;
    console.log(headheight)
}

// shrinks the header as the page is scrolled, caps at 25% of original size
function shrinkHeader() {
    if(document.body.scrollTop > 50 || document.documentElement.scrollTop > 50){
        var originalremgn = 5;
        var originalremlogl = 1;
        var distance = document.documentElement.scrollTop;
        var newdist = distance-50
        if(newdist < 150){
            var rules = document.styleSheets[0].cssRules;
            var pct = (.75*(newdist/150));
            var pctlog = 3*(newdist/150);
            if(pctlog > 1){
                pctlog = 1;
            }
            console.log(`main shrink: ${newdist}`);
            document.getElementById("groupname").style.fontSize = `${originalremgn * (1-pct)}rem`;
            document.getElementById("logline").style.fontSize = `${originalremlogl * (1-pctlog)}rem`;
        }
        else {
            document.getElementById("groupname").style.fontSize = `${originalremgn * .25}rem`;
            document.getElementById("logline").style.fontSize = 0;
        }
    }
    else {
        console.log("resetting..")
        document.getElementById("logline").style.fontSize = null;
        document.getElementById("groupname").style.fontSize = null;
    }
}
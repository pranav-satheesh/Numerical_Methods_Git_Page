(function(){/*

 Copyright The Closure Library Authors.
 SPDX-License-Identifier: Apache-2.0
*/
'use strict';var m;function aa(a){var b=0;return function(){return b<a.length?{done:!1,value:a[b++]}:{done:!0}}}function p(a){var b="undefined"!=typeof Symbol&&Symbol.iterator&&a[Symbol.iterator];return b?b.call(a):{next:aa(a)}}var ba="function"==typeof Object.create?Object.create:function(a){function b(){}b.prototype=a;return new b},q="function"==typeof Object.defineProperties?Object.defineProperty:function(a,b,c){if(a==Array.prototype||a==Object.prototype)return a;a[b]=c.value;return a};
function ca(a){a=["object"==typeof globalThis&&globalThis,a,"object"==typeof window&&window,"object"==typeof self&&self,"object"==typeof global&&global];for(var b=0;b<a.length;++b){var c=a[b];if(c&&c.Math==Math)return c}throw Error("Cannot find global object");}var u=ca(this);function v(a,b){if(b){var c=u;a=a.split(".");for(var d=0;d<a.length-1;d++){var f=a[d];f in c||(c[f]={});c=c[f]}a=a[a.length-1];d=c[a];b=b(d);b!=d&&null!=b&&q(c,a,{configurable:!0,writable:!0,value:b})}}var w;
if("function"==typeof Object.setPrototypeOf)w=Object.setPrototypeOf;else{var x;a:{var da={D:!0},ea={};try{ea.__proto__=da;x=ea.D;break a}catch(a){}x=!1}w=x?function(a,b){a.__proto__=b;if(a.__proto__!==b)throw new TypeError(a+" is not extensible");return a}:null}var z=w;
function A(a,b){a.prototype=ba(b.prototype);a.prototype.constructor=a;if(z)z(a,b);else for(var c in b)if("prototype"!=c)if(Object.defineProperties){var d=Object.getOwnPropertyDescriptor(b,c);d&&Object.defineProperty(a,c,d)}else a[c]=b[c];a.ma=b.prototype}
v("Promise",function(a){function b(h){this.b=0;this.g=void 0;this.a=[];var e=this.c();try{h(e.resolve,e.reject)}catch(g){e.reject(g)}}function c(){this.a=null}function d(h){return h instanceof b?h:new b(function(e){e(h)})}if(a)return a;c.prototype.b=function(h){if(null==this.a){this.a=[];var e=this;this.c(function(){e.g()})}this.a.push(h)};var f=u.setTimeout;c.prototype.c=function(h){f(h,0)};c.prototype.g=function(){for(;this.a&&this.a.length;){var h=this.a;this.a=[];for(var e=0;e<h.length;++e){var g=
h[e];h[e]=null;try{g()}catch(k){this.f(k)}}}this.a=null};c.prototype.f=function(h){this.c(function(){throw h;})};b.prototype.c=function(){function h(k){return function(n){g||(g=!0,k.call(e,n))}}var e=this,g=!1;return{resolve:h(this.G),reject:h(this.f)}};b.prototype.G=function(h){if(h===this)this.f(new TypeError("A Promise cannot resolve to itself"));else if(h instanceof b)this.H(h);else{a:switch(typeof h){case "object":var e=null!=h;break a;case "function":e=!0;break a;default:e=!1}e?this.v(h):this.h(h)}};
b.prototype.v=function(h){var e=void 0;try{e=h.then}catch(g){this.f(g);return}"function"==typeof e?this.I(e,h):this.h(h)};b.prototype.f=function(h){this.j(2,h)};b.prototype.h=function(h){this.j(1,h)};b.prototype.j=function(h,e){if(0!=this.b)throw Error("Cannot settle("+h+", "+e+"): Promise already settled in state"+this.b);this.b=h;this.g=e;this.l()};b.prototype.l=function(){if(null!=this.a){for(var h=0;h<this.a.length;++h)l.b(this.a[h]);this.a=null}};var l=new c;b.prototype.H=function(h){var e=this.c();
h.w(e.resolve,e.reject)};b.prototype.I=function(h,e){var g=this.c();try{h.call(e,g.resolve,g.reject)}catch(k){g.reject(k)}};b.prototype.then=function(h,e){function g(t,y){return"function"==typeof t?function(T){try{k(t(T))}catch(U){n(U)}}:y}var k,n,r=new b(function(t,y){k=t;n=y});this.w(g(h,k),g(e,n));return r};b.prototype.catch=function(h){return this.then(void 0,h)};b.prototype.w=function(h,e){function g(){switch(k.b){case 1:h(k.g);break;case 2:e(k.g);break;default:throw Error("Unexpected state: "+
k.b);}}var k=this;null==this.a?l.b(g):this.a.push(g)};b.resolve=d;b.reject=function(h){return new b(function(e,g){g(h)})};b.race=function(h){return new b(function(e,g){for(var k=p(h),n=k.next();!n.done;n=k.next())d(n.value).w(e,g)})};b.all=function(h){var e=p(h),g=e.next();return g.done?d([]):new b(function(k,n){function r(T){return function(U){t[T]=U;y--;0==y&&k(t)}}var t=[],y=0;do t.push(void 0),y++,d(g.value).w(r(t.length-1),n),g=e.next();while(!g.done)})};return b});
v("Symbol",function(a){function b(f){if(this instanceof b)throw new TypeError("Symbol is not a constructor");return new c("jscomp_symbol_"+(f||"")+"_"+d++,f)}function c(f,l){this.a=f;q(this,"description",{configurable:!0,writable:!0,value:l})}if(a)return a;c.prototype.toString=function(){return this.a};var d=0;return b});
v("Symbol.iterator",function(a){if(a)return a;a=Symbol("Symbol.iterator");for(var b="Array Int8Array Uint8Array Uint8ClampedArray Int16Array Uint16Array Int32Array Uint32Array Float32Array Float64Array".split(" "),c=0;c<b.length;c++){var d=u[b[c]];"function"===typeof d&&"function"!=typeof d.prototype[a]&&q(d.prototype,a,{configurable:!0,writable:!0,value:function(){return fa(aa(this))}})}return a});function fa(a){a={next:a};a[Symbol.iterator]=function(){return this};return a}
function ha(a){if(!(a instanceof Object))throw new TypeError("Iterator result "+a+" is not an object");}function ia(){this.h=!1;this.c=null;this.l=void 0;this.a=1;this.f=this.g=0;this.j=this.b=null}function B(a){if(a.h)throw new TypeError("Generator is already running");a.h=!0}m=ia.prototype;m.A=function(a){this.l=a};function C(a,b){a.b={F:b,C:!0};a.a=a.g||a.f}m.return=function(a){this.b={return:a};this.a=this.f};m.fa=function(a){this.b={u:a};this.a=this.f};
m.pa=function(a,b){a=p(a);var c=a.next();ha(c);if(c.done)this.l=c.value,this.a=b;else return this.c=a,a=c.value,this.a=b,{value:a}};m.u=function(a){this.a=a};m.ia=function(a){this.g=0;this.f=a||0};m.J=function(a,b,c){c?this.j[c]=this.b:this.j=[this.b];this.g=a||0;this.f=b||0};m.ga=function(a,b){b=this.j.splice(b||0)[0];(b=this.b=this.b||b)?b.C?this.a=this.g||this.f:void 0!=b.u&&this.f<b.u?(this.a=b.u,this.b=null):this.a=this.f:this.a=a};m.M=function(a){return new ja(a)};
function ja(a){this.b=a;this.a=[];for(var b in a)this.a.push(b);this.a.reverse()}ja.prototype.c=function(){for(;0<this.a.length;){var a=this.a.pop();if(a in this.b)return a}return null};function ka(a){this.a=new ia;this.b=a}function la(a,b){B(a.a);var c=a.a.c;if(c)return D(a,"return"in c?c["return"]:function(d){return{value:d,done:!0}},b,a.a.return);a.a.return(b);return E(a)}
function D(a,b,c,d){try{var f=b.call(a.a.c,c);ha(f);if(!f.done)return a.a.h=!1,f;var l=f.value}catch(h){return a.a.c=null,C(a.a,h),E(a)}a.a.c=null;d.call(a.a,l);return E(a)}function E(a){for(;a.a.a;)try{var b=a.b(a.a);if(b)return a.a.h=!1,{value:b.value,done:!1}}catch(c){a.a.l=void 0,C(a.a,c)}a.a.h=!1;if(a.a.b){b=a.a.b;a.a.b=null;if(b.C)throw b.F;return{value:b.return,done:!0}}return{value:void 0,done:!0}}
function ma(a){this.next=function(b){B(a.a);a.a.c?b=D(a,a.a.c.next,b,a.a.A):(a.a.A(b),b=E(a));return b};this.throw=function(b){B(a.a);a.a.c?b=D(a,a.a.c["throw"],b,a.a.A):(C(a.a,b),b=E(a));return b};this.return=function(b){return la(a,b)};this[Symbol.iterator]=function(){return this}}function na(a){function b(d){return a.next(d)}function c(d){return a.throw(d)}new Promise(function(d,f){function l(h){h.done?d(h.value):Promise.resolve(h.value).then(b,c).then(l,f)}l(a.next())})}
v("Object.setPrototypeOf",function(a){return a||z});function F(a,b){return Object.prototype.hasOwnProperty.call(a,b)}
var oa=function(){function a(){function c(){}new c;Reflect.construct(c,[],function(){});return new c instanceof c}if("undefined"!=typeof Reflect&&Reflect.construct){if(a())return Reflect.construct;var b=Reflect.construct;return function(c,d,f){c=b(c,d);f&&Reflect.setPrototypeOf(c,f.prototype);return c}}return function(c,d,f){void 0===f&&(f=c);f=ba(f.prototype||Object.prototype);return Function.prototype.apply.call(c,f,d)||f}}();v("Reflect.construct",function(){return oa});
v("WeakMap",function(a){function b(g){this.a=(e+=Math.random()+1).toString();if(g){g=p(g);for(var k;!(k=g.next()).done;)k=k.value,this.set(k[0],k[1])}}function c(){}function d(g){var k=typeof g;return"object"===k&&null!==g||"function"===k}function f(g){if(!F(g,h)){var k=new c;q(g,h,{value:k})}}function l(g){var k=Object[g];k&&(Object[g]=function(n){if(n instanceof c)return n;f(n);return k(n)})}if(function(){if(!a||!Object.seal)return!1;try{var g=Object.seal({}),k=Object.seal({}),n=new a([[g,2],[k,
3]]);if(2!=n.get(g)||3!=n.get(k))return!1;n.delete(g);n.set(k,4);return!n.has(g)&&4==n.get(k)}catch(r){return!1}}())return a;var h="$jscomp_hidden_"+Math.random();l("freeze");l("preventExtensions");l("seal");var e=0;b.prototype.set=function(g,k){if(!d(g))throw Error("Invalid WeakMap key");f(g);if(!F(g,h))throw Error("WeakMap key fail: "+g);g[h][this.a]=k;return this};b.prototype.get=function(g){return d(g)&&F(g,h)?g[h][this.a]:void 0};b.prototype.has=function(g){return d(g)&&F(g,h)&&F(g[h],this.a)};
b.prototype.delete=function(g){return d(g)&&F(g,h)&&F(g[h],this.a)?delete g[h][this.a]:!1};return b});
v("Map",function(a){function b(){var e={};return e.o=e.next=e.head=e}function c(e,g){var k=e.a;return fa(function(){if(k){for(;k.head!=e.a;)k=k.o;for(;k.next!=k.head;)return k=k.next,{done:!1,value:g(k)};k=null}return{done:!0,value:void 0}})}function d(e,g){var k=g&&typeof g;"object"==k||"function"==k?l.has(g)?k=l.get(g):(k=""+ ++h,l.set(g,k)):k="p_"+g;var n=e.b[k];if(n&&F(e.b,k))for(e=0;e<n.length;e++){var r=n[e];if(g!==g&&r.key!==r.key||g===r.key)return{id:k,list:n,index:e,i:r}}return{id:k,list:n,
index:-1,i:void 0}}function f(e){this.b={};this.a=b();this.size=0;if(e){e=p(e);for(var g;!(g=e.next()).done;)g=g.value,this.set(g[0],g[1])}}if(function(){if(!a||"function"!=typeof a||!a.prototype.entries||"function"!=typeof Object.seal)return!1;try{var e=Object.seal({x:4}),g=new a(p([[e,"s"]]));if("s"!=g.get(e)||1!=g.size||g.get({x:4})||g.set({x:4},"t")!=g||2!=g.size)return!1;var k=g.entries(),n=k.next();if(n.done||n.value[0]!=e||"s"!=n.value[1])return!1;n=k.next();return n.done||4!=n.value[0].x||
"t"!=n.value[1]||!k.next().done?!1:!0}catch(r){return!1}}())return a;var l=new WeakMap;f.prototype.set=function(e,g){e=0===e?0:e;var k=d(this,e);k.list||(k.list=this.b[k.id]=[]);k.i?k.i.value=g:(k.i={next:this.a,o:this.a.o,head:this.a,key:e,value:g},k.list.push(k.i),this.a.o.next=k.i,this.a.o=k.i,this.size++);return this};f.prototype.delete=function(e){e=d(this,e);return e.i&&e.list?(e.list.splice(e.index,1),e.list.length||delete this.b[e.id],e.i.o.next=e.i.next,e.i.next.o=e.i.o,e.i.head=null,this.size--,
!0):!1};f.prototype.clear=function(){this.b={};this.a=this.a.o=b();this.size=0};f.prototype.has=function(e){return!!d(this,e).i};f.prototype.get=function(e){return(e=d(this,e).i)&&e.value};f.prototype.entries=function(){return c(this,function(e){return[e.key,e.value]})};f.prototype.keys=function(){return c(this,function(e){return e.key})};f.prototype.values=function(){return c(this,function(e){return e.value})};f.prototype.forEach=function(e,g){for(var k=this.entries(),n;!(n=k.next()).done;)n=n.value,
e.call(g,n[1],n[0],this)};f.prototype[Symbol.iterator]=f.prototype.entries;var h=0;return f});var G=this||self;function pa(){for(var a=["MathJax"],b=G,c=0;c<a.length;c++)if(b=b[a[c]],null==b)return null;return b}
function qa(a){var b=typeof a;if("object"==b)if(a){if(a instanceof Array)return"array";if(a instanceof Object)return b;var c=Object.prototype.toString.call(a);if("[object Window]"==c)return"object";if("[object Array]"==c||"number"==typeof a.length&&"undefined"!=typeof a.splice&&"undefined"!=typeof a.propertyIsEnumerable&&!a.propertyIsEnumerable("splice"))return"array";if("[object Function]"==c||"undefined"!=typeof a.call&&"undefined"!=typeof a.propertyIsEnumerable&&!a.propertyIsEnumerable("call"))return"function"}else return"null";
else if("function"==b&&"undefined"==typeof a.call)return"object";return b}function H(a){var b=qa(a);return"array"==b||"object"==b&&"number"==typeof a.length}var ra=Date.now||function(){return+new Date};var sa=Array.prototype.indexOf?function(a,b){return Array.prototype.indexOf.call(a,b,void 0)}:function(a,b){if("string"===typeof a)return"string"!==typeof b||1!=b.length?-1:a.indexOf(b,0);for(var c=0;c<a.length;c++)if(c in a&&a[c]===b)return c;return-1},ta=Array.prototype.forEach?function(a,b,c){Array.prototype.forEach.call(a,b,c)}:function(a,b,c){for(var d=a.length,f="string"===typeof a?a.split(""):a,l=0;l<d;l++)l in f&&b.call(c,f[l],l,a)};
function ua(a){return Array.prototype.concat.apply([],arguments)}function va(a){var b=a.length;if(0<b){for(var c=Array(b),d=0;d<b;d++)c[d]=a[d];return c}return[]};var wa="StopIteration"in G?G.StopIteration:{message:"StopIteration",stack:""};function xa(){}xa.prototype.next=function(){throw wa;};xa.prototype.a=function(){return this};function I(a,b){this.b={};this.a=[];this.f=this.c=0;var c=arguments.length;if(1<c){if(c%2)throw Error("Uneven number of arguments");for(var d=0;d<c;d+=2)this.set(arguments[d],arguments[d+1])}else if(a)if(a instanceof I)for(c=a.s(),d=0;d<c.length;d++)this.set(c[d],a.get(c[d]));else for(d in a)this.set(d,a[d])}m=I.prototype;m.m=function(){J(this);for(var a=[],b=0;b<this.a.length;b++)a.push(this.b[this.a[b]]);return a};m.s=function(){J(this);return this.a.concat()};
m.ba=function(a){for(var b=0;b<this.a.length;b++){var c=this.a[b];if(K(this.b,c)&&this.b[c]==a)return!0}return!1};m.K=function(a,b){if(this===a)return!0;if(this.c!=a.c)return!1;b=b||ya;J(this);for(var c,d=0;c=this.a[d];d++)if(!b(this.get(c),a.get(c)))return!1;return!0};function ya(a,b){return a===b}m.ca=function(){return 0==this.c};m.aa=function(){this.b={};this.f=this.c=this.a.length=0};
function J(a){if(a.c!=a.a.length){for(var b=0,c=0;b<a.a.length;){var d=a.a[b];K(a.b,d)&&(a.a[c++]=d);b++}a.a.length=c}if(a.c!=a.a.length){var f={};for(c=b=0;b<a.a.length;)d=a.a[b],K(f,d)||(a.a[c++]=d,f[d]=1),b++;a.a.length=c}}m.get=function(a,b){return K(this.b,a)?this.b[a]:b};m.set=function(a,b){K(this.b,a)||(this.c++,this.a.push(a),this.f++);this.b[a]=b};m.forEach=function(a,b){for(var c=this.s(),d=0;d<c.length;d++){var f=c[d],l=this.get(f);a.call(b,l,f,this)}};
m.oa=function(){for(var a=new I,b=0;b<this.a.length;b++){var c=this.a[b];a.set(this.b[c],c)}return a};m.na=function(){J(this);for(var a={},b=0;b<this.a.length;b++){var c=this.a[b];a[c]=this.b[c]}return a};m.O=function(){return za(this,!0)};m.S=function(){return za(this,!1)};function za(a,b){J(a);var c=0,d=a.f,f=new xa;f.next=function(){if(d!=a.f)throw Error("The map has changed since the iterator was created");if(c>=a.a.length)throw wa;var l=a.a[c++];return b?l:a.b[l]};return f}
function K(a,b){return Object.prototype.hasOwnProperty.call(a,b)};function Aa(a){if(a.m&&"function"==typeof a.m)return a.m();if("string"===typeof a)return a.split("");if(H(a)){for(var b=[],c=a.length,d=0;d<c;d++)b.push(a[d]);return b}b=[];c=0;for(d in a)b[c++]=a[d];return b}
function Ba(a,b,c){if(a.forEach&&"function"==typeof a.forEach)a.forEach(b,c);else if(H(a)||"string"===typeof a)ta(a,b,c);else{if(a.s&&"function"==typeof a.s)var d=a.s();else if(a.m&&"function"==typeof a.m)d=void 0;else if(H(a)||"string"===typeof a){d=[];for(var f=a.length,l=0;l<f;l++)d.push(l)}else for(l in d=[],f=0,a)d[f++]=l;f=Aa(a);l=f.length;for(var h=0;h<l;h++)b.call(c,f[h],d&&d[h],a)}};var Ca=/^(?:([^:/?#.]+):)?(?:\/\/(?:([^\\/?#]*)@)?([^\\/?#]*?)(?::([0-9]+))?(?=[\\/?#]|$))?([^?#]+)?(?:\?([^#]*))?(?:#([\s\S]*))?$/;function Da(a,b){if(a){a=a.split("&");for(var c=0;c<a.length;c++){var d=a[c].indexOf("="),f=null;if(0<=d){var l=a[c].substring(0,d);f=a[c].substring(d+1)}else l=a[c];b(l,f?decodeURIComponent(f.replace(/\+/g," ")):"")}}};function L(a,b){this.b=this.l=this.h="";this.f=null;this.j=this.c="";this.g=this.v=!1;if(a instanceof L){this.g=void 0!==b?b:a.g;Ea(this,a.h);var c=a.l;M(this);this.l=c;c=a.b;M(this);this.b=c;Fa(this,a.f);c=a.c;M(this);this.c=c;N(this,Ga(a.a));a=a.j;M(this);this.j=a}else a&&(c=String(a).match(Ca))?(this.g=!!b,Ea(this,c[1]||"",!0),a=c[2]||"",M(this),this.l=O(a),a=c[3]||"",M(this),this.b=O(a,!0),Fa(this,c[4]),a=c[5]||"",M(this),this.c=O(a,!0),N(this,c[6]||"",!0),a=c[7]||"",M(this),this.j=O(a)):(this.g=
!!b,this.a=new P(null,this.g))}m=L.prototype;m.toString=function(){var a=[],b=this.h;b&&a.push(Q(b,Ha,!0),":");var c=this.b;if(c||"file"==b)a.push("//"),(b=this.l)&&a.push(Q(b,Ha,!0),"@"),a.push(encodeURIComponent(String(c)).replace(/%25([0-9a-fA-F]{2})/g,"%$1")),c=this.f,null!=c&&a.push(":",String(c));if(c=this.c)this.b&&"/"!=c.charAt(0)&&a.push("/"),a.push(Q(c,"/"==c.charAt(0)?Ia:Ja,!0));(c=this.a.toString())&&a.push("?",c);(c=this.j)&&a.push("#",Q(c,Ka));return a.join("")};
m.resolve=function(a){var b=new L(this),c=!!a.h;c?Ea(b,a.h):c=!!a.l;if(c){var d=a.l;M(b);b.l=d}else c=!!a.b;c?(d=a.b,M(b),b.b=d):c=null!=a.f;d=a.c;if(c)Fa(b,a.f);else if(c=!!a.c){if("/"!=d.charAt(0))if(this.b&&!this.c)d="/"+d;else{var f=b.c.lastIndexOf("/");-1!=f&&(d=b.c.substr(0,f+1)+d)}f=d;if(".."==f||"."==f)d="";else if(-1!=f.indexOf("./")||-1!=f.indexOf("/.")){d=0==f.lastIndexOf("/",0);f=f.split("/");for(var l=[],h=0;h<f.length;){var e=f[h++];"."==e?d&&h==f.length&&l.push(""):".."==e?((1<l.length||
1==l.length&&""!=l[0])&&l.pop(),d&&h==f.length&&l.push("")):(l.push(e),d=!0)}d=l.join("/")}else d=f}c?(M(b),b.c=d):c=""!==a.a.toString();c?N(b,Ga(a.a)):c=!!a.j;c&&(a=a.j,M(b),b.j=a);return b};function Ea(a,b,c){M(a);a.h=c?O(b,!0):b;a.h&&(a.h=a.h.replace(/:$/,""))}function Fa(a,b){M(a);if(b){b=Number(b);if(isNaN(b)||0>b)throw Error("Bad port number "+b);a.f=b}else a.f=null}function N(a,b,c){M(a);b instanceof P?(a.a=b,La(a.a,a.g)):(c||(b=Q(b,Ma)),a.a=new P(b,a.g));return a}
m.ka=function(a,b){return N(this,a,b)};m.N=function(){return O(this.a.toString())};m.Y=function(){return this.a.toString()};m.ja=function(a,b){M(this);Array.isArray(b)||(b=[String(b)]);Na(this.a,a,b);return this};m.R=function(a){return this.a.m(a)};m.P=function(a){return this.a.get(a)};m.da=function(a){return(!this.b&&!a.b||this.b==a.b)&&(null==this.f&&null==a.f||this.f==a.f)};
m.ha=function(){M(this);var a=Math.floor(2147483648*Math.random()).toString(36)+Math.abs(Math.floor(2147483648*Math.random())^ra()).toString(36);M(this);this.a.set("zx",a);return this};m.Z=function(a){M(this);R(this.a,a);return this};m.la=function(a){this.v=a;return this};m.ea=function(){return this.v};function M(a){if(a.v)throw Error("Tried to modify a read-only Uri");}m.$=function(a){this.g=a;this.a&&La(this.a,a);return this};
function O(a,b){return a?b?decodeURI(a.replace(/%25/g,"%2525")):decodeURIComponent(a):""}function Q(a,b,c){return"string"===typeof a?(a=encodeURI(a).replace(b,Oa),c&&(a=a.replace(/%25([0-9a-fA-F]{2})/g,"%$1")),a):null}function Oa(a){a=a.charCodeAt(0);return"%"+(a>>4&15).toString(16)+(a&15).toString(16)}var Ha=/[#\/\?@]/g,Ja=/[#\?:]/g,Ia=/[#\?]/g,Ma=/[#\?@]/g,Ka=/#/g;function P(a,b){this.b=this.a=null;this.c=a||null;this.f=!!b}
function S(a){a.a||(a.a=new I,a.b=0,a.c&&Da(a.c,function(b,c){a.add(decodeURIComponent(b.replace(/\+/g," ")),c)}))}m=P.prototype;m.W=function(){S(this);return this.b};m.add=function(a,b){S(this);this.c=null;a=V(this,a);var c=this.a.get(a);c||this.a.set(a,c=[]);c.push(b);this.b+=1;return this};function R(a,b){S(a);b=V(a,b);K(a.a.b,b)&&(a.c=null,a.b-=a.a.get(b).length,a=a.a,K(a.b,b)&&(delete a.b[b],a.c--,a.f++,a.a.length>2*a.c&&J(a)))}m.T=function(){this.a=this.c=null;this.b=0};
m.X=function(){S(this);return 0==this.b};function Pa(a,b){S(a);b=V(a,b);return K(a.a.b,b)}m.U=function(a){var b=this.m();return 0<=sa(b,a)};m.forEach=function(a,b){S(this);this.a.forEach(function(c,d){ta(c,function(f){a.call(b,f,d,this)},this)},this)};m.s=function(){S(this);for(var a=this.a.m(),b=this.a.s(),c=[],d=0;d<b.length;d++)for(var f=a[d],l=0;l<f.length;l++)c.push(b[d]);return c};
m.m=function(a){S(this);var b=[];if("string"===typeof a)Pa(this,a)&&(b=ua(b,this.a.get(V(this,a))));else{a=this.a.m();for(var c=0;c<a.length;c++)b=ua(b,a[c])}return b};m.set=function(a,b){S(this);this.c=null;a=V(this,a);Pa(this,a)&&(this.b-=this.a.get(a).length);this.a.set(a,[b]);this.b+=1;return this};m.get=function(a,b){if(!a)return b;a=this.m(a);return 0<a.length?String(a[0]):b};function Na(a,b,c){R(a,b);0<c.length&&(a.c=null,a.a.set(V(a,b),va(c)),a.b+=c.length)}
m.toString=function(){if(this.c)return this.c;if(!this.a)return"";for(var a=[],b=this.a.s(),c=0;c<b.length;c++){var d=b[c],f=encodeURIComponent(String(d));d=this.m(d);for(var l=0;l<d.length;l++){var h=f;""!==d[l]&&(h+="="+encodeURIComponent(String(d[l])));a.push(h)}}return this.c=a.join("&")};m.L=function(a){S(this);this.a.forEach(function(b,c){0<=sa(a,c)||R(this,c)},this);return this};function Ga(a){var b=new P;b.c=a.c;a.a&&(b.a=new I(a.a),b.b=a.b);return b}
function V(a,b){b=String(b);a.f&&(b=b.toLowerCase());return b}function La(a,b){b&&!a.f&&(S(a),a.c=null,a.a.forEach(function(c,d){var f=d.toLowerCase();d!=f&&(R(this,d),Na(this,f,c))},a));a.f=b}m.V=function(a){for(var b=0;b<arguments.length;b++)Ba(arguments[b],function(c,d){this.add(d,c)},this)};var Qa={};function Ra(a,b){var c=Qa[a];if(void 0!==c&&(!c.B||Date.now()<=c.B+3E5))return c.p;c=new Promise(function(f,l){b.onload=function(){return f(b)};b.onerror=function(h){b.parentNode&&b.parentNode.removeChild(b);l(h)};document.head.appendChild(b)});var d={B:0,p:c};c.catch(function(){return d.B=+new Date});Qa[a]=d;return c};var Sa=!/^\s*class\s*\{\s*\}\s*$/.test(function(){}.toString());/*

 Copyright (c) 2016 The Polymer Project Authors. All rights reserved.
 This code may only be used under the BSD style license found at http://polymer.github.io/LICENSE.txt
 The complete set of authors may be found at http://polymer.github.io/AUTHORS.txt
 The complete set of contributors may be found at http://polymer.github.io/CONTRIBUTORS.txt
 Code distributed by Google as part of the polymer project is also
 subject to an additional IP rights grant found at http://polymer.github.io/PATENTS.txt
*/
(function(){if(Sa&&!HTMLElement.es5Shimmed&&void 0!==window.Reflect&&void 0!==window.customElements&&!window.customElements.polyfillWrapFlushCallback){var a=HTMLElement;window.HTMLElement=function(){return Reflect.construct(a,[],this.constructor)};HTMLElement.prototype=a.prototype;HTMLElement.prototype.constructor=HTMLElement;HTMLElement.es5Shimmed=!0;Object.setPrototypeOf(HTMLElement,a)}})();function W(a){var b=HTMLElement.call(this)||this;a&&Ta(a);return b}A(W,HTMLElement);W.prototype.f=function(){console.warn(this.tagName,"has not implemented update")};W.prototype.b=function(a){a=void 0===a?"":a;return document.createRange().createContextualFragment(a||"")};
W.prototype.c=function(a,b,c){a&&b?a.parentNode.replaceChild(document.importNode(b,!0),a):!b&&a?a.parentNode.removeChild(a):!a&&b&&(c?(a=document.importNode(b,!0),c.parentElement.insertBefore(a,c.nextSibling)):this.appendChild(document.importNode(b,!0)))};function Ta(a){"string"===typeof a&&(a=[a]);document.body.dispatchEvent(new CustomEvent("devsite-load-custom-elements",{bubbles:!0,detail:a}))};var X=new Map;function Y(a){var b=W.call(this)||this;a&&Ta(a);return b}A(Y,W);Y.prototype.connectedCallback=function(){var a=this.constructor,b=X.get(a);b?console.error("can't add duplicate element to page: "+b.tagName):X.set(a,this)};Y.prototype.disconnectedCallback=function(){var a=this.constructor;X.get(a)===this&&X.delete(a)};Y.prototype.disconnectedCallback=Y.prototype.disconnectedCallback;Y.prototype.connectedCallback=Y.prototype.connectedCallback;var Ua=null;function Z(){var a=Y.call(this)||this;a.a="";return a}A(Z,Y);Z.prototype.connectedCallback=function(){this.a=this.getAttribute("config");Va(this)};
function Va(a){var b;na(new ma(new ka(function(c){switch(c.a){case 1:if(pa()){c.u(2);break}b=Ua;if(!b){var d=new URL(DevsiteApp.getStaticPath()+"/js/mathjax_excluding_assistive_mml/MathJax.js",document.location.origin);d.search="?delayStartupUntil=configured";var f=void 0===f?null:f;d=d.href;d=d instanceof L?new L(d):new L(d,void 0);var l=document.createElement("script");l.src=d.toString();f&&(l.type=f);Ua=b=Ra(d.toString(),l)}c.g=3;f=b;c.a=5;return{value:f};case 5:c.a=2;c.g=0;break;case 3:return c.g=
0,Ua=c.b=null,c.return();case 2:pa()&&(f={config:[],showProcessingMessages:!1,positionToHash:!1,tex2jax:{inlineMath:[["$","$"],["\\(","\\)"]],processEscapes:!0}},a.a&&(f.config=[a.a+".js"]),MathJax.Hub.Config(f),MathJax.Hub.Configured(),MathJax.Hub.Queue(["Typeset",MathJax.Hub]),a.dispatchEvent(new CustomEvent("devsite-content-updated"))),c.a=0}})))}Z.prototype.connectedCallback=Z.prototype.connectedCallback;try{window.customElements.define("devsite-mathjax",Z)}catch(a){console.warn("devsite.app.customElement.DevsiteMathJax",a)};}).call(this);